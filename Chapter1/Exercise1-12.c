/*
    Write a program that prints its input one word per line.
*/

#include <stdio.h>

/*
    control could have the value of:
        0) When a char is read.
        1) When a separator (' ','\n' or '\t') is read.
        2 or more) When more than 1 separator is read consecutively
*/

int main()
{
    int c, control;
    control = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            control = control + 1;
            if (control <= 1)
                putchar('\n');
        } else
        {
            control = 0;
            putchar(c);
        }
    }
}