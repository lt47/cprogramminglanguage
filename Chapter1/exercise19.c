#include <stdio.h>

/* Reverse char [].*/

#define MAX_CHARS_IN_LINE 1000

int my_getline(char current_line[], int max_chars_allowed);
void reverse(char current_line[]);


int main(){
    char current_line[MAX_CHARS_IN_LINE];
    int current_chars_in_line = 0;

    while((current_chars_in_line = my_getline(current_line, MAX_CHARS_IN_LINE) != 0)){
        printf("Original string: %s\n", current_line);
        reverse(current_line);
        printf("Reversed string: %s\n", current_line);
    }
}

int my_getline(char s[], int max_chars_allowed){
    char c = 0;
    int character_count = 0;
    for(int i = 0; ((c = getchar()) != '\n') && (c != EOF) && (i < MAX_CHARS_IN_LINE-1); i++){
        s[i] = c;
        character_count = i;
    }

    if(c == '\n'){
        character_count++;
        s[character_count] = '\n';
    }

    return character_count;
}

void reverse(char s[]){
    int right_char_position = 0;

    for(int i = 0; i < MAX_CHARS_IN_LINE; i++){
        right_char_position++;
        if(s[i] == '\n'){
            break;
        }
    }


    int left_char_position = 0;
    // Start from just before the '\n' character. Leaving the newline character in place. 
    right_char_position--;
    char temp = 0;

    while(left_char_position < right_char_position){
        temp = s[left_char_position];
        s[left_char_position] = s[right_char_position];
        s[right_char_position] = temp;
        left_char_position++;
        right_char_position--;
    }

    
}