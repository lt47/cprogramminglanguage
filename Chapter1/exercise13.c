#include <stdio.h>

/* Goal is to print a histograms of words in a vertical orientation. */

#define OUTSIDE_A_WORD 0
#define INSIDE_A_WORD 1
#define MAX_WORD_LENGTH 10

int main(){
    char c;
    int word_state = OUTSIDE_A_WORD;
    int current_word_length = 0;
    int word_array[MAX_WORD_LENGTH];
    
    // Initialize array. 
    for (int i = 0; i < MAX_WORD_LENGTH; i++){
        word_array[i] = 0;
    }

    while ((c = getchar()) != EOF){
        /* Rough definition of a word in the text is a group of characters that does not contain a space, tab, or newline. */
         if (c == ' ' || c == '\t' || c == '\n'){
            if (word_state == INSIDE_A_WORD){
                // Marking the conclusion of that word. 
                word_state = OUTSIDE_A_WORD;
            }
            if (current_word_length > 0){
                /* In short, this will go to the position of the word length int in the array and increment its value.*/
                ++word_array[current_word_length];
                // No current word, so set the char count to 0.
                current_word_length = 0;
            }
        }
        // Marking the start of the word.
        else if (word_state == OUTSIDE_A_WORD){
            word_state = INSIDE_A_WORD;
            ++current_word_length;
        }
        // Marking the continuation of the word. 
        else {
            ++current_word_length;
        }
    }

    int current_histogram_height = MAX_WORD_LENGTH;

    for (int i = MAX_WORD_LENGTH; i > 0; i--){    
        for (int j = 1; j < MAX_WORD_LENGTH; j++){
            if(word_array[j] >= current_histogram_height){
                printf("%3c", '*');
            }
            else{
                printf("%3c", ' ');
            }
        }
        current_histogram_height--;
        printf("\n");
        
    }
    for (int j = 1; j < MAX_WORD_LENGTH; j++){
        printf("---");
    }
    printf("\n");
    for (int y = 1; y < MAX_WORD_LENGTH; y++){
        printf("%3d", y);
    }
    printf("\n");

}