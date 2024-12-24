#include <stdio.h>

/* Remove all comments from a C program. */

int main(){
    char c = 0;
    char previous_c = 0;
    int default_comment = 0;
    int asterisk_comment = 0;

    while((c = getchar()) != EOF){
        if(((previous_c == '\n' || previous_c == ' ' || previous_c == '\t') && (c == '/' || c == ' ' || c == '\t'))){
            previous_c = c;
            continue;
        }
        if(((previous_c == '/') && (c == '/'))){
            default_comment = 1;
        }
        else if(((previous_c == '/') && (c == '*'))){
            asterisk_comment = 1;
        }
        else if((c == '\n') && (default_comment == 1)){
            putchar(c);
            default_comment = 0;
        }
        else if((asterisk_comment == 1) && (previous_c == '*') && (c == '/')){
            asterisk_comment = 0;
        }
        else if((default_comment == 0) && (asterisk_comment == 0)){
            putchar(c);
        }
        previous_c = c;
    }
}