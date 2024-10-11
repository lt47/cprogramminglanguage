#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
    for(int i = 0; i < n; i++){
        *s++ = *t++;
    }
    while(*s != '\0'){
        *s++ = '\0';
    }

}

void strncat(char *s, char *t, int n)
{
    for(; *s; *s++)
        ;
    for(int i = 0; i < n && *t; i++){
        // One char at a time.
        *s++ = *t++;
    }
    // Crucial part of the code, but why? I think char [] need to end in a null terminator to be valid. Will confirm. 
    *s = '\0';
}

int strncmp(char *s, char *t, int n){
    // What are the space considerations of me initializing char lists this way and not specifying the exact size?
    // important to not increment it before it is compared so that it breaks on the characters that werent the same. 
    for(int i = 0; i < n && *s == *t; i++, s++, t++){
        if(*s == '\0'){
            printf("%d\n", 0);
            return 0;
        }
    }
    printf("%d\n", *s - *t);
    return *s - *t;
}

int main(){
    char test[] = "test12";
    char test1[] = "tent34";

    //strncpy(test1, test, 4);
    //strncat(test1, test, 4);
    printf("%s\n", test1);
    strncmp(test1, test, 4);
}