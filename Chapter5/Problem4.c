#include <stdio.h>
#include <string.h>
/* Function strend(s,t) that returns 1 if the string t occurs at the end of
the string s. */

int strend(char *s, char *t)
{
    // Save the state before changes to compare the strings.
    char *savedSState = s;
    char *savedTState = t;

    // Iterate to the end (when it reaches a new line or null terminator.)
    for (; *s; s++)
        ;
    for (; *t; t++)
        ;

    // Decrement and check if the characters match.strcmp(s, t) == 0
    while (*s == *t)
    {
        // Check if we've gotten to the beginning of t.
        if (t == savedTState)
        {
            printf("%d", 1);
            return 1;
        }
        s--;
        t--;
    }
    printf("%d", 0);
    return 0;
}

/* Tried to enact the same solution that takes arrays as arguments.
Its the same code. Arrays and pointers are indeed closely related in C. */
int altstrend(char s[], char t[])
{
    // Save the state before changes to compare the strings.
    char *savedSState = s;
    char *savedTState = t;

    // Iterate to the end (when it reaches a new line or null terminator.)
    for (; *s; s++)
        ;
    for (; *t; t++)
        ;

    // Decrement and check if the characters match.strcmp(s, t) == 0
    while (*s == *t)
    {
        // Check if we've gotten to the beginning of t.
        if (t == savedTState)
        {
            printf("%d", 1);
            return 1;
        }
        s--;
        t--;
    }
    printf("%d", 0);
    return 0;
}

int main()
{
    char firstStr[] = "test";
    char secondStr[] = "ost";

    altstrend(firstStr, secondStr);
    strend(firstStr, secondStr);
}