#include <stdio.h>
/*strcat: concatenate t to the end of s; s must be big enough*/
void original_strcat(char s[], char t[]){
    int i, j;

    i = j = 0;

    while (s[i] != '\0'){i++;} /* find end of s*/
    /* copy t */
    while ((s[i++] = t[j++]) != '\0')
        ;

    printf(s);
}

/* In exercise 3, I am asked to create a pointer version of the above. */
/*I have learned that C does not have a pass by reference as C++ does.*/
void new_strcat(char *s[], char *t[]){
    int i, j;

    i = j = 0;

    while (*s[i] != '\0'){i++;} /* find end of s*/
    /* copy t */
    while ((*s[i++] = *t[j++]) != '\0')
        ;

    printf(*s);
}

int main(){
    char firstStr[] = "test";
    char secondStr[] = "not";

    new_strcat(&firstStr, &secondStr);

}

