#include <stdio.h>

// Plan is to count number of each kind of bracket and make sure everything is equal as far as opening and closing. 

int main(){
    int opening_parenthesis_count = 0;
    int closing_parenthesis_count = 0;
    int opening_bracket_count = 0;
    int closing_bracket_count = 0;
    int opening_braces_count = 0;
    int closing_braces_count = 0;

    char c = 0;

    /* This approach does not account for these elements appearing in comment blocks. */
    while((c = getchar()) != EOF){
        switch(c){
            case '(':
                opening_parenthesis_count++;
                break;
            case '[':
                opening_bracket_count++;
                break;
            case '{':
                opening_braces_count++;
                break;
            case ')':
                closing_parenthesis_count++;
                break;
            case ']':
                closing_bracket_count++;
                break;
            case '}':
                closing_braces_count++;
                break;
        }
    }

    if((opening_parenthesis_count == closing_parenthesis_count) && (opening_bracket_count == closing_bracket_count) && (opening_braces_count == closing_braces_count)){
        printf("Everything is honky dorey.\n");
    }
    else{
        printf("Something is up buddy boy.\n");
    }

}