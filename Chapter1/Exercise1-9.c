#include <stdio.h>

/*
    Remember press ctrl + d to send 'EOF' through console
*/

int main(int argc, char const *argv[])
{
    int c, n;

    n = 0;

    while ((c=getchar()) != EOF)
    {
        if (c != ' ')
        {
            n = 0;
            putchar(c);
        } else
        {
            n = n + 1;
            if (n>=2)
            {
                putchar('\b');
                n = 1;
            }
            putchar(' ');
        }  
    }

    return 0;
}