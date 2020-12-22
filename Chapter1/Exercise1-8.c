/*
    Write a program to count blanks, tabs and newlines
*/

#include <stdio.h>

/*
    Remember press ctrl + d to send 'EOF' through console
*/

int main(int argc, char const *argv[])
{
    int c, numTabs, numBlanks, numNewLine;

    numTabs = 0;
    numBlanks = 0;
    numNewLine = 0;

    while ((c=getchar()) != EOF)
    {
        if (c == '\t')
        {
            ++numTabs;
        } else if (c == ' ')
        {
            ++numBlanks;
        } else if (c == '\n')
        {
            ++numNewLine;
        }    

        //printf("Number of Tabs: %d, Number of Blanks: %d, Number of New lines: %d\n", numTabs, numBlanks, numNewLine);    
    }

    printf("Number of Tabs: %d, Number of Blanks: %d, Number of New lines: %d\n", numTabs, numBlanks, numNewLine);

    return 0;
}
