#include <stdio.h>

void check_eof_expression(){
    int c;
    c = getchar() != EOF;
    printf("The character c is equal to: %d\n", c);
    printf("The EOF constant stands for: %d\n", EOF);
}

int main(){
    check_eof_expression();
}