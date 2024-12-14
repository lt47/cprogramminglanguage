#include <stdio.h>

int main(){
    char c;
    char previous_c;

    /* I had some difficulty with this question 
    because I wasnt factoring in that the char only 
    takes a single character. I'd managed to enter 
    multiple in the terminal. Will test that.*/
    while((c = getchar()) != EOF){
        if (c != ' '){
            previous_c = c;
            putchar(c);
        }
        else if (c == ' '){
            if (previous_c == ' '){
                continue;
            }
            else{
                previous_c = c;
                putchar(c);
            }
            
        }
    }
}