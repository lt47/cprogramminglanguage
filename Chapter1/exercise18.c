#include <stdio.h>

/* Remove trailing spaces and tab characters from a line.*/

#define MAX_CHARS_IN_LINE 1000

int getline(char current_line[], int max_chars_allowed);
void remove_trailing_spaces(char current_line[]);


int main(){
    char current_line[MAX_CHARS_IN_LINE];
    int current_chars_in_line = 0;

    while((current_chars_in_line = getline(current_line, MAX_CHARS_IN_LINE) != 0)){
        printf("Spaces not removed: %s\n", current_line);
        remove_trailing_spaces(current_line);
        printf("Spaces have been removed: %s\n", current_line);
    }
}

int getline(char current_line[], int max_chars_allowed){
    char c = 0;
    int character_count = 0;
    for(int i = 0; ((c = getchar()) != '\n') && (c != EOF) && (i < MAX_CHARS_IN_LINE-1); i++){
        current_line[i] = c;
        character_count = i;
    }

    if(c == '\n'){
        character_count++;
        current_line[character_count] = '\n';
    }

    return character_count;
}

void remove_trailing_spaces(char current_line[]){
    int i;
    for(i = 0; i < MAX_CHARS_IN_LINE; i++){
        if(current_line[i] == '\n'){
            current_line[i] == '\0';
            break;
        }
    }
    // Whats before '\n'. 
    i--;

    while(current_line[i] == ' ' || current_line[i] == '\t'){
        current_line[i] = '\0';
        i--;
    }

    // Get the last char that isnt a tab or space
    i++;
    current_line[i] = '\n';
    // End with a null terminator.
    i++;
    current_line[i] = '\0';
}