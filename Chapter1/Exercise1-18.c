/*
    write a program to remove trailing blanks and tabs from each line of input, 
    and to delete entirely blank lines
*/

#include <stdio.h>
#define MAXLINE 1000
#define blankLine -1

int get_line(char line[], int maxline);
int clean(char line[], int length);

int main()
{
    int length, newLength;
    char line[MAXLINE];

    while ((length = get_line(line, MAXLINE)) > 0)
    {
        newLength = clean(line, length);
        if (newLength > 0)
            printf("%s", line);
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


int clean(char line[], int length)
{
    if (length == 1)
        return blankLine;

    for (int i = length-2; i >= 0; i--)     //"-2" due to s[length] == '\0' and s[length-1] == '\n'
    {
        if (line[i]==' ' || line[i]=='\t')
        {
            line[i] = '\n';
            line[i+1] = '\0';
            --length;
            continue;
        }
        else
            return length;
    }
}