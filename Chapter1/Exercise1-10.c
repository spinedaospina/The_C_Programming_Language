/*
    Write a program to copy its input to its output, replacing each tab by \t, each backspace by  \b, and each backslash by \\. 
    This makes tabs and backspace visible in an ambiguous way.
*/

#include <stdio.h>

/*
    Remember press ctrl + d to send 'EOF' through console
*/

int main(int argc, char const *argv[])
{
    int c;

    while ((c=getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        } else if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        } else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        } else
        {
            putchar(c);
        }
    }

    return 0;
}