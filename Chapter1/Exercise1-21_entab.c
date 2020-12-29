/*
    Write a program entab that replaces strings of blanks by the
    minimun number of tabs and blanks to achieve the same spacing. Use the same
    tab stop as for detab. When either a tab or a single blank would suffice to reach
    a tab stop, which should be given preference?
*/


#include <stdio.h>

#define numberOfBlanksPerTab 4

int main(int argc, char const *argv[])
{
    int counterOfBlanks = 0, c;
    while ((c=getchar()) != EOF)
    {
        if (c == ' ')
            ++counterOfBlanks;
        else if (c == '\t')
            counterOfBlanks += numberOfBlanksPerTab;
        else
        {
            if (counterOfBlanks != 0)
            {
                while (counterOfBlanks >= numberOfBlanksPerTab)
                {
                    putchar('\t');
                    counterOfBlanks -= numberOfBlanksPerTab;            
                }
                for (int i = 0; i < counterOfBlanks; i++)
                    putchar(' ');  
            }
            counterOfBlanks = 0;
            putchar(c);
        }  
    }
    return 0;
}
