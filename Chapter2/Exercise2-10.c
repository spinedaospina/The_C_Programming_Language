/*
    Rewrite the function lower, which converts upper case
    letters to lower case, with a conditional expression
    instead of if-else
*/

#include <stdio.h>
#define MAXLENGTH 1000

int main(int argc, char const *argv[])
{
    int i = 0, s[MAXLENGTH];

    // Get string
    printf("Write a string: ");
    while ((s[i] = getchar()) != EOF)
    {
        (s[i] >= 'A' && s[i] <= 'Z') ? (s[i] = s[i] + 'a' - 'A') : (s[i] = s[i]);
        i++;
    }
    s[i] = '\0';

    // Print the string modified
    i = 0;
    printf("\nThe new string is: ");
    while (s[i] != '\0')
        putchar(s[i++]);
    printf("\n");
       
    
    return 0;
}