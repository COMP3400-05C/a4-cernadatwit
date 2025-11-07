#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* TODO: First check the number of arguments, and if none print an error message. 

Then identify the middle argument if there are an odd number of arguments, 
or the middle 2 arguments if there are an even number of arguments.

Last, use the exec system call to exec the command. 
Make sure you handle the -1 return because you may have typos in your arguments.
*/

//exec int exec_agc = (end - start ) + 2;
//execv - Variable num of arguments as an ARRAY
int main(int argc, char* argv[]) {
    // next 6 lines - execs 'ls -l' as in bash
    if (argc<2){ //argc is counter of arguments
        fprintf(stderr, "ERROR: No arguments");
        // printf("echo $?");
        return 1; 
    }
    int num_of_args = argc-1;
    int mid = num_of_args / 2;
    char *execArgs[4];
    execArgs[0] = "/bin/echo";

    if (num_of_args%2==0){
        execArgs[1] = argv[mid];
        execArgs[2] = argv[mid+1];  
        execArgs[3] = NULL;
    } else {
        execArgs[1] = argv[mid+1];  
        execArgs[2] = NULL; 
    }

    if (execv("/bin/echo",execArgs)==-1){
        write(2,"Error: No argument",19);
        exit(1);
    }

    return 0;

}

/* How to Execute 'ls -l' in current dir
    char* eargs[] = { "ls", "-l", NULL };
    int eret = execv("/bin/ls", eargs);
    if(eret == -1) {
        perror("exec");
        return 1;
    }

    if ((argc-1)==i){
            temp = capitalize(argv[i]);
            printf("%s",temp);
            free(temp);
        } else {
            temp = capitalize(argv[i]);
            printf("%s,",temp);
            free(temp);
        }
*/

/*
EXPECTED OUTPUT: 
For this assignment, you are to write a program that uses the exec system call 
TO use the echo program. This program will read N arguments, 
and use echo to print the middle 1 or 2 arguments. 
Do NOT use the printf function or other stdio functions (unless for debugging purposes).

Background on using exec()
The exec() system can be a bit tricky to use. 
There are multiple (!) different versions of this system call, 
and the version we'll be using is execv. 
This means it takes a variable number of arguments as an array (notice the "v").
*/