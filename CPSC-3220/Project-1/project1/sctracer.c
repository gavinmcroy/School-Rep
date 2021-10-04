#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int sysCallNumber;
    int timesCalled;
} Node;

char **parseArguments(char *argString);

FILE *basicErrorChecking(int argc, char *argv[]);

int standByForCalL(pid_t childID);

int keepTabsOnChild(pid_t childID);

void buildTable(Node *table, int size);

void addToTable(Node *table, int callNum);

void fileOutput(Node *table, int size, FILE *out);


/* ./programName "./test arg1 arg2" <fileName> */
int main(int argc, char **argv) {
    const int MAX_SYS_CALL = 512;
    Node sysCallTable[MAX_SYS_CALL];
    buildTable(sysCallTable, MAX_SYS_CALL);

    FILE *out = basicErrorChecking(argc, argv);

    /* prevents argv from getting destroyed by strtok. The * 2 is an insurance that duplicate big enough */
    char *duplicate = (char *) malloc(sizeof(char) * strlen(argv[1]) * 2);
    strcpy(duplicate, argv[1]);

    /* This is redundant, */
    //char *programName = parseName((const char **) argv, argc);
    /* exec requires strings to be a 2D table instead of a string of arguments */
    char **parsedArguments = parseArguments(duplicate);
    char *programName = parsedArguments[0];

    // printf("%s loaded\n", parsedArguments[0]);
    // printf("%s\n", argv[1]);

    /* Prepare child for tracing */
    pid_t child = fork();
    if (child == 0) {
        ptrace(PTRACE_TRACEME);
        int error = execvp(programName, parsedArguments);
        /* if execvp returns a negative number, there was an error */
        if (error < 0) {
            fprintf(stderr, "exec error\n");
            exit(-1);
        }
        /* stop myself --allow the parent to get ready to trace me */
        kill(getpid(), SIGSTOP);

    } /* Parent preparing to listen to child */
    else {
        keepTabsOnChild(child);
        while (true) {
            int error = standByForCalL(child);
            int syscall_num;

            if (error != 0) {
                break;
            }

            /* read out the saved value of the RAX register,
             * which contains the system call number
             * For 32-bit machines, you would use EAX. */
            syscall_num = ptrace(PTRACE_PEEKUSER,
                                 child, sizeof(long) * ORIG_RAX, NULL);

            //printf("My child called system call #%d.\n", syscall_num);

            addToTable(sysCallTable, syscall_num);

            /* Without this everything prints twice? */
            error = standByForCalL(child);
            if (error != 0) {
                break;
            }
        }
        fileOutput(sysCallTable, MAX_SYS_CALL, out);
    }
}

char **parseArguments(char *argString) {
    /* Setup our arguments table */
    const int MAX_ARGS = 1024;
    const int MAX_ARG_STR_SIZE = 1024;
    /* Accidentally put char instead of char*, the most painful bug */
    char **args = (char **) malloc(sizeof(char *) * MAX_ARGS);
    for (int i = 0; i < MAX_ARGS; i++) {
        args[i] = (char *) malloc(sizeof(char) * MAX_ARG_STR_SIZE);
    }

    /* No matter what we will have at least one argument parsed */
    const char delim[2] = " ";
    char *token = strtok(argString, delim);
    strcpy(args[0], token);
    // printf("BEFORE: %s %lu\n",args[0],strlen(args[0]));

    /* walk through other tokens */
    int argIterator = 1;
    while (token != NULL) {
        token = strtok(NULL, delim);
        if (token == NULL) {
            break;
        }
        strcpy(args[argIterator], token);
        argIterator++;
    }
    /* Denotes the end of the argument list */
    args[argIterator] = NULL;

    /* prints entire args table to ensure it is functioning. Debug statement
    int i = 0;
    printf("AFTER: %s %lu\n",args[0],strlen(args[0]));
    while (args[i] != NULL) {
        printf("%s\n", args[i]);
        i++;
    } */
    return args;
}


FILE *basicErrorChecking(int argc, char *argv[]) {
    const int MIN_ARGS = 3;
    const int FILE_LOCATION = 2;
    if (argc < MIN_ARGS) {
        fprintf(stderr, "error not enough arguments\n");
        exit(-1);
    }
    /* The [2] is always going to be the file name */
    FILE *out = fopen(argv[FILE_LOCATION], "w");

    if (!out) {
        fprintf(stderr, "File creation error\n");
        exit(-1);
    }
    return out;

}

int standByForCalL(pid_t childID) {
    int status;
    while (true) {
        //Request: I want to wait for a system call
        ptrace(PTRACE_SYSCALL, childID, 0, 0);
//      actually wait for child status to change
        waitpid(childID, &status, 0);

        //there are differented reasons that a child's
        //status might change. Check to see if the child exited
        if (WIFEXITED(status)) {
            //the child exited...let's exit too
            //printf("Child exited\n");
            return 1;
        }
        if ((WIFSTOPPED(status) &&
             WSTOPSIG(status) & 0x80)) {
            return 0;
        }
        //wait until the process is stopped or bit 7 is set in
        //the status (see man page comment on
        //PTRACE_O_TRACESYSGOOD)
    }
}

int keepTabsOnChild(pid_t childID) {
    //Called by the parent to keep tabs on certain child process
    int status;

    //wait for the child to stop itself
    int error = waitpid(childID, &status, 0);
    if (error == -1) {
        return -1;
    }

    //this option makes it easier to distinguish normal traps from
    //system calls
    error = ptrace(PTRACE_SETOPTIONS, childID, 0,
                   PTRACE_O_TRACESYSGOOD);
    if (error == -1) {
        return -1;
    }
    return 0;
}

void buildTable(Node *table, int size) {
    for (int i = 0; i < size; i++) {
        table[i].sysCallNumber = -1;
        table[i].timesCalled = 0;
    }
}

void addToTable(Node *table, int callNum) {
    table[callNum].timesCalled++;
    table[callNum].sysCallNumber = callNum;
}

void fileOutput(Node *table, int size, FILE *out) {
    for (int i = 0; i < size; i++) {
        if (table[i].sysCallNumber != -1) {
            fprintf(out, "%d\t%d\n", table[i].sysCallNumber, table[i].timesCalled);
        }
    }
    fclose(out);
}


/* DEAD CODE */
//char *parseString(char *argv[]) {
//    const int BUFFER = 100;
//    char *programName = (char *) malloc(sizeof(char) * BUFFER);
//    char *pointer = argv[1];
//    int counter = 0;
//    while ((*pointer) != '\0') {
//        /* Program string has been found */
//        if (*pointer == '.' && pointer[counter + 1] == '/') {
//            /* Copy until we hit a space */
//            int tempCounter = 0;
//            while (*pointer != ' ') {
//                if (*pointer == '\0')
//                    break;
//                programName[tempCounter] = *pointer;
//                tempCounter++;
//                pointer++;
//            }
//            /* We are finished with the loop. Condition when program contains arg with string */
//            break;
//        }
//        pointer++;
//        counter++;
//    }
//    return programName;
//}

//char *parseName(const char **argv, int argc);
//char *parseName(const char **argv, int argc) {
//    /* argv[1] is where the program name should be. We are duplicating the string to be parsed */
//    char *duplicate = (char *) malloc(sizeof(char) * strlen(argv[1]));
//    const int MAX_BUFFER = 1024;
//    strcpy(duplicate, argv[1]);
//    /* set our iterator to the first character in the string */
//    char *iterator = duplicate;
//    int i = 0;
//    while ((*iterator) != ' ' && (*iterator) != '\0') {
//        iterator++;
//        i++;
//    }
//    duplicate[i] = '\0';
//    char *name = (char *) malloc(sizeof(char) * MAX_BUFFER);
//    strcpy(name, duplicate);
//
//    //printf("%s", name);
//
//    return name;
//}
/* DEAD CODE */
