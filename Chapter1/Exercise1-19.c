/*
    Write a function reverse(s) that reverses the characters string s.
    Use it to write a program that reverse its input a line at a time.
*/

// Using the same Exercise1-18 code (and adding the copy function from 1-17)

#include <stdio.h>
#define MAXLINE 1000
#define blankLine -1

int get_line(char line[], int maxline);
int clean(char line[], int length);
void copy(char to[], char from[]);
void reverse(char line[], int length);

int main()
{
    int length, newLength;
    char line[MAXLINE];

    while ((length = get_line(line, MAXLINE)) > 0)
    {
        newLength = clean(line, length);
        if (newLength > 0)
        {
            reverse(line,newLength);
            printf("%s", line);
        }
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


void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}


void reverse(char line[], int length)
{
    char auxiliar[MAXLINE];
    for (int i = length-2; i >= 0; i--)  //"-2" due to s[length] == '\0' and s[length-1] == '\n'
    {
        auxiliar[length-2-i] = line[i];            // "length-2-1" == From 0 to length-2
    }
    auxiliar[length-1] = '\n';
    auxiliar[length] = '\0';
    
    copy(line,auxiliar);
}