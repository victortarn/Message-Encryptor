#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void main(int argc, char *argv[]) { 
    int n;
    char *msg;
    int msg_len;
    char enc[msg_len + 1]; 

    if (argc == 1){
        printf("%s", "Usage: encrypt shift str");
        printf("\n");
        exit(0);
    }
    else if (argc != 3){
        fprintf(stderr, "Wrong number of arguments");
        printf("\n");
        exit(1);
    }

    n = atoi(argv[1]);
    msg = argv[2];
    msg_len = strlen(msg);
    enc[msg_len] = '\0';
    n = n % 26;

    if (n < 0){
        n = 26 + n;
    }

    for (int i = 0; i < msg_len; i++){
        enc[i]= toupper(msg[i]);

        if ((int)enc[i] >= 65 && (int)enc[i] <= 90){
            if ((int)enc[i] + n > 90){
                enc[i] = (char)((int)enc[i]+n-26);
            }
            else {
                enc[i] = (char)((int)enc[i]+n);
            }
        }
    }
    
    printf("%s", enc);
    printf("\n");
    exit(0);   
}