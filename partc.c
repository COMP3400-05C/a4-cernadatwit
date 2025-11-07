#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


// TODO: Include more header files (read the manpages to find out more!)
/*For this assignment, you are to write a program that uses the fork-exec flow. 
The parent process will wait for the child process, which runs the program grep to complete. 
If the child process is successful, print FOUND, if not, print an error message.
*/
int main(int argc, char* argv[]) {
    // TODO: Complete and document
    if (argc != 3) {
        write(2, "ERROR: No arguments", 20);
        // write(2, "Usage: ./partc <word> <filename>\n", 33);
        return 1;
    }

    char *word = argv[1];
    char *filename = argv[2];

    pid_t pid = fork();

    if (pid < 0) {
        write(2, "Error: fork failed\n", 20);
        return 1;
    }

    if (pid == 0) {
        // Child process → run grep
        char *exec_args[] = {"/usr/bin/grep", "-s", "-q", word, filename, NULL};
        execv("/usr/bin/grep", exec_args);

        // If execv returns, it failed
        write(2, "Error: exec failed\n", 20);
        exit(3);
    } else {
        // Parent process → wait for child
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            int exit_code = WEXITSTATUS(status);
            if (exit_code == 0) {
                // Found
                write(1, "FOUND: ", 7);
                write(1, word, strlen(word));
                write(1, "\n", 1);
            } else if (exit_code == 1) {
                // Not found
                write(1, "NOT FOUND: ", 11);
                write(1, word, strlen(word));
                write(1, "\n", 1);
            } else if (exit_code == 2) {
                // File not found
                write(1, "ERROR: ", 7);
                write(1, filename, strlen(filename));
                write(1, " doesn't exist\n", 15);
                return 2;
            } else {
                write(2, "Unknown error\n", 14);
                return 3;
            }
        }
    }

    return 0;
}
