#include <stdio.h>

int main(){
    int lower_limit, upper_limit, step;
    float fahrenheit_value, celsius_value;

    fahrenheit_value = 0.0;

    lower_limit = 0;
    upper_limit = 300;
    step = 20;

    printf("F to C Conversion Table\n");
    printf("----------------------------\n");
    printf("%3s %6s\n", "F", "C");
    printf("----------------------------\n");
    while (upper_limit >= fahrenheit_value){
        celsius_value = (5.0/9.0) * (fahrenheit_value - 32.0);
        printf("%3.0f %6.1f\n", fahrenheit_value, celsius_value);
        fahrenheit_value += step;
    }


    celsius_value = 0.0;
    fahrenheit_value = 0.0;

    printf("\n\nC to F Conversion Table\n");
    printf("----------------------------\n");
    printf("%3s %6s\n", "C", "F");
    printf("----------------------------\n");
    while (upper_limit >= celsius_value){
        fahrenheit_value = ((9.0/5.0) * celsius_value) + 32.0;
        printf("%3.0f %6.1f\n", celsius_value, fahrenheit_value);
        celsius_value += step;
    }
}