#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
    pid_t childOne, childTwo;

    //Create array for pipe
    int mainPipe[2];

    //Create file descriptors for pipe
    //[0] is the input end (standard input)
    //[1] is the output end (standard output)
    pipe(mainPipe);

    //Create first child process
    switch (childOne = fork()) {
        //Check if child process failed to create
        case -1:
            printf("Error creating first process!");
            break;
        //Child process was created and fork() returned a 0
        case 0:
            //Duplicate the output end of the pipe to STDOUT_FILENO
            //This will connect the stdout of this process to the stdin of the second child process
            dup2(mainPipe[1], STDOUT_FILENO);
            close(mainPipe[0]);
            close(mainPipe[1]);

            //Child 1 executes the ls -F process using the path to "ls"
            //execlp() always ends with NULL
            execlp("ls", "ls", "-F", NULL);

            //If reached then the process terminated successfully
            exit(0);
        default:
            //A positive value is returned to the parent representing the pid of the child
            //Nothing happens here
    }

    //Create second child process
    switch (childTwo = fork()) {
        case -1:
            printf("Error creating second process!");
            break;
        case 0:
            //Duplicate the input end of the pipe to STDIN_FILENO
            dup2(mainPipe[0], STDIN_FILENO);
            close(mainPipe[0]);
            close(mainPipe[1]);

            //Child 2 executes the nl process after checking the output from Child 1
            execlp("nl", "nl", NULL);
            exit(0);
        default:
            //Nothing happens
    }

    //Any process that has access to the pipe must close it
    //Parent closes the pipe
    close(mainPipe[0]);
    close(mainPipe[1]);

    //Parent makes sure both processes have been created successfully and waits for its children to terminate
    if (childOne >= 0) {
        wait(NULL);
        if (childTwo >= 0) {
            wait(NULL);
        }
    }

    return 0;
}