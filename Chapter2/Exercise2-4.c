/*
    Write an alternative version of squeeze (s1, s2),
    that deletes each character in s1 that matches
    any character in the string s2
*/
#include <stdio.h>
#define MAXLENGTH 100
#define true 1
#define false 0

void squeeze(char s1[], char s2[]);


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
    
    squeeze(s1, s2);

    // Print s1
    printf("The result is: %s\n\n", s1);    
        
    return 0;
}


void squeeze(char s1[], char s2[]){
    int i, j, k;
    int repet = false;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        for (k = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
                repet = true;
        
        if(!repet)
            s1[j++] = s1[i];

        repet = false;
    }

    s1[j] = '\0';
}