#include <stdio.h>

#define TAB_SPACE 8

void detab(void);

int main(){
    printf("\t,.\t,..\t,\n");
    detab();
}

void detab(void){
    char c = 0;
    int chars_before_tab = 0;
    printf("Detab time:\n");

    while((c = getchar()) != EOF){
        if(c != '\t'){
            putchar(c);
            chars_before_tab++;
        }
        // Special case for tab char right after newline. 
        else if(c == '\n'){
            chars_before_tab = 0;
        }
        else{
            int spaces_to_insert = TAB_SPACE - (chars_before_tab % TAB_SPACE);
            for(int i = 0; i < spaces_to_insert; i++){
                putchar(' ');
            }
            chars_before_tab = 0;
        }
    }
}