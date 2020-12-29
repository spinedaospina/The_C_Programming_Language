/*
    Write a program to "fold" long input lines into two or more
    shorter lines after the last non-blank character that occurs before the n-th
    column of the input. Make sure your program does something intelligent with very
    long lines, and if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>

#define maxLengthOfLines 10
#define MAXLINE 1000

int get_line(char line[], int maxline);


int main()
{
    int length, i, front = 0, back = 0, lastBlankOrTab = 0;
    char line[MAXLINE];

    while ((length = get_line(line, MAXLINE)) > 0)
    {
        while (back != length)
        {
            //Check lastBlankOrTab value
            for (i = back; i < front; i++)
            {
                if (line[i] == ' ' || line[i] == '\t')
                    lastBlankOrTab = i;
            }

            if (back == lastBlankOrTab)
            {
                for (i = (back+1); i < front; i++)
                    printf("%c", line[i]);
                printf("\n");
                lastBlankOrTab = front;
            } else
            {
                for (i = back; i < lastBlankOrTab; i++)
                    printf("%c", line[i]);
                printf("\n");
            }
            
            back = lastBlankOrTab;
            
            if ((back + maxLengthOfLines) < length)
                front = back + maxLengthOfLines;
            else
            {
                front = length;
            }
        }

        back = front = lastBlankOrTab = 0;
    }
    return 0;
}


int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
            s[i] = c;
    }
    if (c == '\n') {        
        s[i] = c;
        ++i;
    }   
    s[i] = '\0';

    return i;
}