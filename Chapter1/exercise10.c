#include <stdio.h>


int main(){
    char c;
    // automatic int variables are not guaranteed to be 0.
    
    while((c = getchar()) != EOF){
        switch(c){
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            case '\b':
                putchar('\\');
                putchar('b');
                break;
            case '\\':
                putchar('\\');
                putchar('\\');
                break;
            default:
                putchar(c);
                break;
        }
    }
}