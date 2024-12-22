#include <stdio.h>

#define TAB_SPACE 8

void entab(void);

int main(){
    printf("                                    ,.         ,..     ,\n");
    entab();
}

void entab(void){
    char c = 0;
    int chars_before_spaces = 0;
    int space_char_count = 0;
    char previous_char = 0;
    printf("Entab time:\n");

    while((c = getchar()) != EOF){
        if(c != ' ' && (space_char_count < 8)){
            for(int i = 0; i < space_char_count; i++){
                putchar(' ');
            }
            putchar(c);
            space_char_count = 0;
            chars_before_spaces++;
        }

        else if(c == ' '){
            space_char_count++;
        }
        else if(c != ' ' && previous_char != ' '){
            chars_before_spaces++;
        }

        
        else if(c != ' ' && (space_char_count >= 8)){
            int spaces_for_tab = TAB_SPACE - (chars_before_spaces % TAB_SPACE);
            int tabs_used = 0;
            
            // No remainder 
            for(int x = 0; x < (spaces_for_tab / space_char_count); x++){
                putchar('\t');
                tabs_used++;
            }
            // Remainder dey. 
            for(int y = 0; y < (space_char_count - (tabs_used * spaces_for_tab)); y++){
                putchar(' ');
            }
            putchar(c);
            space_char_count = 0;           
            chars_before_spaces = 0;
        }


        
        if(c != ' ' && previous_char != ' '){
            chars_before_spaces++;
        }
        previous_char = c;

    }
}