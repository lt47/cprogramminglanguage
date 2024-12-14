#include <stdio.h>

/* Count blanks, tabs and newlines. */

int main(){
    char c;
    // automatic int variables are not guaranteed to be 0.
    int blank_count, tab_count, nl_count;
    blank_count = 0;
    tab_count = 0;
    nl_count = 0;
    while((c = getchar()) != EOF){
        switch(c){
            case ' ':
                ++blank_count;
            case '\t':
                ++tab_count;
            case '\n':
                ++nl_count;
            default:
                continue;
        }
    }

    printf("The number of blanks is: %d\n", blank_count);
    printf("The number of tabs is: %d\n", tab_count);
    printf("The number of new lines is: %d\n", nl_count);
}