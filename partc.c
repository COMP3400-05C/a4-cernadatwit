#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// TODO: Include more header files (read the manpages to find out more!)
/*For this assignment, you are to write a program that uses the fork-exec flow. 
The parent process will wait for the child process, which runs the program grep to complete. 
If the child process is successful, print FOUND, if not, print an error message.
*/
int main(int argc, const char* argv[]) {
    // TODO: Complete and document
    if (argc != 3) {
        printf("ERROR: No arguments");
        return 1;
    }
    int pid = fork();
    if (pid == -1){
        perror("fork");
        return 1;
    }
    const char* w = argv[1];
    const char* p = argv[2];

    if (pid == 0){
        char* grep_args[] = {"grep","-s","-q",w,p,NULL};
        int execs = execv("usr/bin/grep",grep_args);

        if (execs==-1){
            perror("exec");
            return 1;
        }
    } else if (pid>0){
        int status;
        wait(&status);

        int exitcCode = WEXITSTATUS(status);
        
        if (exitcCode == 0) {
            printf("FOUND: %s\n",w);
        } else if (exitcCode == 1){
            printf("NOT FOUND: %s\n",w);
        } else {
            printf("ERROR: %s doesn't exist\n",p);
        }
    }

    return 0;
}
