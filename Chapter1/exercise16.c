#include <stdio.h>

#define MAX_LINE_CHARACTERS 1000

int getline(char line[], int char_limit);
void copyline(char to[], char from[]);

int main(){
    char current_line[MAX_LINE_CHARACTERS];
    char longest_line[MAX_LINE_CHARACTERS];

    int max_chars_in_line = 0;
    int current_chars_in_line = 0;

    while((current_chars_in_line = getline(current_line, MAX_LINE_CHARACTERS)) > 0){
        printf("%d : %s\n", current_chars_in_line, current_line);
        if(current_chars_in_line > max_chars_in_line){
            max_chars_in_line = current_chars_in_line;
        }
    }

    printf("Max character count in a line from input is: %d\n", max_chars_in_line);
}

// I dont need to pass by reference here because in C, the actual array is passed in a param. Specifically, the location of the first element in the array. 
int getline(char line[], int char_limit){
    int chars_in_line = 0;
    char c = 0;
    for(int i=0; (i < char_limit-1) && (((c = getchar()) != EOF) && c != '\n'); i++){
        line[i] = c;
        chars_in_line = i; 
    }

    return chars_in_line;
}

void copyline(char to[], char from[]){
    // '\0' = NULL.
    for(int i=0; ((from[i] = to[i]) != '\0'); i++){
        ;
    }
}