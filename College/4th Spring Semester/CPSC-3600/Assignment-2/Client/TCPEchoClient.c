#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include "Practical.h"

int main(int argc, char *argv[]) {

    if (argc < 3 || argc > 4) // Test for correct number of arguments
        DieWithUserMessage("Parameter(s)",
                           "<Server Address/Name> <Echo Word> [<Server Port/Service>]");

    char *server = argv[1];     // First arg: server address/name
    char *echoString = argv[2]; // Second arg: string to echo
    // Third arg (optional): server port/service
    char *service = (argc == 4) ? argv[3] : "echo";

    // Create a connected TCP socket
    int sock = SetupTCPClientSocket(server, service);
    if (sock < 0)
        DieWithUserMessage("SetupTCPClientSocket() failed", "unable to connect");

    //**********************************************************************//
    //---Create our echoString based on file input
    FILE *file = fopen("poem.txt", "r");
    //---echo string needs to equal contents of file
    if (!file) {
        fprintf(stderr, "File Failed to Open");
    }
    //---Make a massive string and sends the file contents at once
    char *fileBuffer = (char *) (malloc(sizeof(char) * 75));
    char *megaString = (char *) malloc(sizeof(char) * 10000);
    while (fscanf(file, "%s", fileBuffer) != EOF) {
        strcat(megaString, fileBuffer);
        strcat(megaString, " ");
    }
    //---TODO Reverse file contents
    /* in place reversal */
//    char *reversal = (char*)(malloc(sizeof(char)*10000));
//    for(int i = 0; i < strlen(megaString); i++){
//        reversal[i] = megaString[strlen(megaString)-i-1];
//    }
    free(fileBuffer);
    //printf("%s",reversal);
    echoString = megaString;
    //**********************************************************************//


    size_t echoStringLen = strlen(echoString); // Determine input length

    // Send the string to the server
    ssize_t numBytes = send(sock, echoString, echoStringLen, 0);
    if (numBytes < 0)
        DieWithSystemMessage("send() failed");
    else if (numBytes != echoStringLen)
        DieWithUserMessage("send()", "sent unexpected number of bytes");

    // Receive the same string back from the server
    unsigned int totalBytesRcvd = 0; // Count of total bytes received
    fputs("Received: ", stdout);     // Setup to print the echoed string
    while (totalBytesRcvd < echoStringLen) {
        char buffer[BUFSIZE]; // I/O buffer
        // Receive up to the buffer size (minus 1 to leave space for
        // a null terminator) bytes from the sender
        numBytes = recv(sock, buffer, BUFSIZE - 1, 0);
        if (numBytes < 0)
            DieWithSystemMessage("recv() failed");
        else if (numBytes == 0)
            DieWithUserMessage("recv()", "connection closed prematurely");
        totalBytesRcvd += numBytes; // Keep tally of total bytes
        buffer[numBytes] = '\0';    // Terminate the string!
        fputs(buffer, stdout);      // Print the buffer
    }

    fputc('\n', stdout); // Print a final linefeed

    close(sock);
    /* ******************************** */
    free(megaString);
    printf("\nClosing Connection. Goodbye! \n");
    /* ******************************** */
    exit(0);
}
