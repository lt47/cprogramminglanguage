#include <stdio.h>

/* Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character 
that occurs before the n-th column of input. Make sure your  program does something intelligent with very long 
lines, and if there are no blanks or tabs before the specified column. */

#define MAX_LINE_LENGTH 20

//void fold_lines(void);

int main(){
    char c = 0;
    char previous_c = 0;
    int current_line_length = 0;

    while((c = getchar()) != EOF){
        if(current_line_length < MAX_LINE_LENGTH){
            putchar(c);
            previous_c = c;
            current_line_length++;
        }
        else if(previous_c == ' ' || previous_c == '\t' || c == ' ' || c == '\t'){
            putchar('\n');
            putchar(c);
            current_line_length = 0;
        }
        else{
            putchar('-');
            putchar('\n');
            putchar(c);
            current_line_length = 0;
        }
    }
}

/* On my first try, the first mistake was not factoring in blanks or spaces at the n-th column. */

/* My plan is to 'intelligently' split the lines by adding a dash if a space does not occur before the n-th column. To me, 
that's more conventional and readable. */