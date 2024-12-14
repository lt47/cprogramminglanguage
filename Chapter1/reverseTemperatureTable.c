#include <stdio.h>

#define LOWER_LIMIT 0
#define UPPER_LIMIT 300
#define STEP 20

int main(){
    int lower_limit, upper_limit, step;
    float fahrenheit_value, celsius_value;

    printf("F to C Conversion Table\n");
    printf("----------------------------\n");
    printf("%3s %6s\n", "F", "C");
    printf("----------------------------\n");
    for (fahrenheit_value = 300.0; fahrenheit_value >= LOWER_LIMIT; fahrenheit_value -= STEP){
        celsius_value = (5.0/9.0) * (fahrenheit_value - 32.0);
        printf("%3.0f %6.1f\n", fahrenheit_value, celsius_value);
    }


    celsius_value = 0.0;
    fahrenheit_value = 0.0;

    printf("\n\nC to F Conversion Table\n");
    printf("----------------------------\n");
    printf("%3s %6s\n", "C", "F");
    printf("----------------------------\n");
    for (celsius_value = 300.0; celsius_value >= LOWER_LIMIT; celsius_value -= STEP){
        fahrenheit_value = ((9.0/5.0) * celsius_value) + 32.0;
        printf("%3.0f %6.1f\n", celsius_value, fahrenheit_value);
    }
}