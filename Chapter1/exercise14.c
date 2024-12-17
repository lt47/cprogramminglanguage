#include <stdio.h>

/* Goal is to print a histograms of the frequency of characters in a horizontal orientation. Its more practical given the number of chars being considered.*/

// Only considering characters up to 'z'
#define MAX_CHAR_VALUE 122

int main(){
    char c;
    int current_word_length = 0;
    int char_array[MAX_CHAR_VALUE];
    
    // Initialize array. 
    for (int i = 0; i < MAX_CHAR_VALUE; i++){
        char_array[i] = 0;
    }

    while ((c = getchar()) != EOF){
        ++char_array[c];
    }

    int current_histogram_height = MAX_CHAR_VALUE;

    // Only print the legible ASCII characters. Begins at 33. 
    for (int j = 33; j < MAX_CHAR_VALUE; j++){
        printf("%3c | ", j);
        if(char_array[j] >= 1){
            // Able to do it this way by setting the max character frequency shown to be 10.
            printf("%.*s", char_array[j], "*************");
        }
        else{
            printf("%3c", ' ');
        }
        printf("\n");
    }


}