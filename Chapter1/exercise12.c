#include <stdio.h>

/* Goal is to print one word per line to the output. */

#define OUTSIDE_A_WORD 0
#define INSIDE_A_WORD 1

int main(){
    char c;
    int word_state = OUTSIDE_A_WORD;

    while ((c = getchar()) != EOF){
        /* Rough definition of a word in the text is a group of characters that does not contain a space, tab, or newline. */
         if (c == ' ' || c == '\t' || c == '\n'){
            if(word_state == INSIDE_A_WORD){
                // Marking the conclusion of that word. 
                putchar('\n');
                word_state = OUTSIDE_A_WORD;
            }
        }
        // Marking the start of the word.
        else if (word_state == OUTSIDE_A_WORD){
            word_state = INSIDE_A_WORD;
            putchar(c);
        }
        // Marking the continuation of the word. 
        else {
            putchar(c);
        }
    }

}

/* This was not as straightforward. Important notes are to determine when you need to keep track of a particular state, identifying all possible states, and the actions to take for each state */