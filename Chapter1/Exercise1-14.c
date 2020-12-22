/*
    Write a program to print a histogram of the frequencies of different characters in its input
*/

/*
    For more info about the ASCII table check: https://www.ascii-code.com/

    The values "firstASCIIcharacter" and "lastASCIIcharacter" were setted looking for the util
    values int the ASCII.
*/

#include <stdio.h>

int main()
{
    int c;
    int firstASCIIcharacter = 32;
    int lastASCIIcharacter = 126;
    int numberOfASCIIcharacters = lastASCIIcharacter - firstASCIIcharacter + 1;     // +1 because start in '0'
    int array[numberOfASCIIcharacters];

    char character;

    for (int i = 0; i < numberOfASCIIcharacters; i++)
        array[i] = 0;
    
    while (1)
    {
        c = getchar();

        if (c == EOF)
            break;

        if(c >= firstASCIIcharacter && c <= lastASCIIcharacter)
            ++array[c-firstASCIIcharacter];
    }

    // print

    //header
    printf("\n|--------------------------------------------------|");
    printf("\n| The frequency of characters used in the file is: |");
    printf("\n|--------------------------------------------------|\n");

    // Content
    for (int i = firstASCIIcharacter; i <= lastASCIIcharacter; i++)
    {
        character = i;
        if (array[i-firstASCIIcharacter] != 0)
            printf("%c: %d\n", character, array[i-firstASCIIcharacter]);      
    }
    
    printf("\n\n");

    return 0;
}