// Page 69. Example. Basics of Functions.
#include <stdio.h>
// Imported the string library to make use of strcpy to feed lines into my char array
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

int custom_getline(char line[], int max);
int strindex(char source[], char searchfor[]);
char pattern[] = "ould"; /* pattern to search for */

/* The order of the functions in the book uses the "scissor" approach whereby the ancillary functions are at the bottom, but this approach is more intuitive to me. */

/* custom_getline: get line into s, return length */
int custom_getline(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* find all lines matching pattern...... */
int main()
{
    char line[MAXLINE];
    /* I got a multi-character constant warning here when i used single quotes. Single quotes are used for a single character. Double are used for string literal. */
    // strcpy(line, "Coulda woulda shoulda\n");
    int found = 0;
    while (custom_getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    return found;
}
