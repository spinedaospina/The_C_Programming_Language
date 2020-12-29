/*
    Write a program detab that replaces tabs in the input with the 
    proper number of blanks to space to the next tab stop. Assume a fixed
    set of tab stops, say every n columns. Should n be a 
    variable or a symbolic parameter?
*/

/*
    You can use te Exercise1-10.sh to verify the program
*/


#include <stdio.h>

#define numberOfBlanksPerTab 4
#define ON 1
#define OFF 0

int main()
{
    int c, replace = OFF;

    while ((c=getchar()) != EOF)
    {
        if (c == '\t')
            replace = ON;

        if (replace == ON)
        {
            for (int i = 0; i < numberOfBlanksPerTab; i++)
                putchar(' ');
            replace = OFF;
        } else
            putchar(c);
    }
    return 0;
}