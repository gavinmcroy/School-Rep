
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int myglobal = 5;



int main() {
    printf("(%d) Before fork: %d\n", getpid(), myglobal);
    pid_t pid = fork();

    if (pid == 0) {
        sleep(1);
        printf("(%d, %d) I'm a child!\n", pid, getpid()); 
    } else {
        //kill(pid,SIGKILL);
        waitpid(pid, NULL, 0);
        printf("(%d, %d) I'm a parent!\n", pid, getpid());    
    }
    myglobal++;
    
}