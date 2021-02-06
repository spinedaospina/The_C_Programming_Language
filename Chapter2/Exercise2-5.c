/*
    Write athe function any (s1, s2), which returns the first location
    in the string s1 where any character from the string s2 occurs, or -1 if s1
    contains no characters from s2.
*/
#include <stdio.h>
#define MAXLENGTH 100
#define false 0
#define true 1

int any(char s1[], char s2[]);


int main()
{
    char s1[MAXLENGTH], s2[MAXLENGTH], c;
    int index;

    // Get 2 strings
    printf("Write s1: ");
    index = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        s1[index++] = c;
    
    printf("Write s2: ");
    index = 0;
    while ((c = getchar()) != '\n' && c != EOF)
        s2[index++] = c;
    printf("\n");
    
    // Print results
    printf("The result is: %d\n\n", any(s1, s2));    
        
    return 0;
}


int any(char s1[], char s2[]){
    int i, k, needToBreak = false, location = -1;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (k = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
            {
                location = i;
                needToBreak = true;
                break;
            }
        
        if(needToBreak)
            break;
    }
    
    return location;
}