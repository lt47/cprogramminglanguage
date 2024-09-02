#include <stdio.h>
/*strcat: concatenate t to the end of s; s must be big enough*/
void original_strcat(char s[], char t[])
{
    int i, j;

    i = j = 0;

    // while (s[i] != '\0'){i++;} /* find end of s*/
    /* So I just discovered that while (s[i] != '\0') is equivalent to while(s[i]).
     * while(s[i]) just evaluates until it reaches a null character/endpoint/terminator i.e. '\0' - the ASCII value of zero.
     */
    while (s[i])
    {
        i++;
    } /* find end of s*/
    /* copy t */
    while ((s[i++] = t[j++]) != '\0')
        ;

    printf("%s", s);
}

/* In exercise 3, I am asked to create a pointer version of the above. */
/*I have learned that C does not have a pass by reference as C++ does.*/
void new_strcat(char *s, char *t)
{

    while (*s)
    {
        s++;
    } /* find end of s*/

    /* copy t to end of s*/
    while ((*s++ = *t++))
        ;

    /*It doesnt make sense to me why t is the pointer that is modified here when all of t is supposed to be added to the end of s. See Line 50 notes.*/
    printf("%s\n", t);
}

int main()
{
    char firstStr[] = "test";
    char secondStr[] = "not";

    // original_strcat(firstStr, secondStr);

    new_strcat(firstStr, secondStr);
    /*It makes sense here. Now 's' or 'firstStr' is the concatenated result. And 't' or 'secondStr' remains as is.
    * I think the explanation for this is that s and t are not the same as their pointer values. In new_strcat, s is incremented till it becomes '\0' i.e. null. 
    * It remains at that value and only its pointer is modified. I still dont know why I cant see the result of the modification within the function, my suspicion is that it is a memory access thing.  
    */
    printf("%s\n", firstStr);
    printf("%s\n", secondStr);
}
