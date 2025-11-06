#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>

// TODO: Include more header files (read the manpages to find out more!)

//exec int exec_agc = (end - start ) + 2;
//execv - Variable num of arguments as an ARRAY
int main(int argc, char* argv[]) {
    // next 6 lines - execs 'ls -l' as in bash
    if (argc==1){ //argc is counter of arguments
        fprintf(stderr, "ERROR No arguments");
        return 1; 
    }
    char* temp;
    int diff = argc-1;
    for (int i=1;i<argc;i++){
        
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
*/