#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
// TODO: Include more header files (read the manpages to find out more!)

char* capitalize(const char* s) {
    while (s!=NULL){
        int len = 0;
        // if (isalnum(s))
        // const char* str = *s;
        while (s[len]!='\0'){
            len++;
        }
        int size = len+1;
        char* temp = malloc(size*sizeof(char));
        // for (int i = 0; s[i] != '\0'; i++) {
        //     temp[i] = toupper((unsigned char)s[i]);
        // }
        for (int i=0;i<len;i++){
            // if (!(isalpha(s[i]))) continue;
            if (islower(s[i])){
                temp[i] = toupper((unsigned char) s[i]);
            } else {
                temp[i] = s[i];
            }
        }
        temp[len]='\0';
        return temp;

    }
    return NULL;
}

int main(int argc, char* argv[]) {
    // [./parta; args1; args2]
    // skip argv[0]
    if (argc==1){ //argc is counter of arguments
        fprintf(stderr, "ERROR: No arguments\n");
        // printf("echo $");
        return 1; 
    }
    // printf("argc: %d\n",argc);
    char* temp;
    for (int i=1;i<argc;i++){
        if ((argc-1)==i){
            temp = capitalize(argv[i]);
            printf("%s",temp);
            free(temp);
        } else {
            temp = capitalize(argv[i]);
            printf("%s,",temp);
            free(temp);
        }
    }
    // free(temp);
    return 0;
}
