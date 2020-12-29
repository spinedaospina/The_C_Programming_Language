/*
    Write a program to remove all comments from a C program.
    Don't forget to handle quoted strings and characters constants properly.
    C comments do no nest.
*/

/*
    Comments 1 to 5 added because this program will be the input for himself.
*/

#include <stdio.h>

int main()
{
    int c;  //Comment #1

    while ((c = getchar()) != EOF)
    {
        if (c != '/')
            putchar(c);         //Comment #2
        else
        {
            //Comment #3
            c = getchar();
            if (c == '/')
            {
                while ((c = getchar()) != '\n' && c != EOF);

                if (c == EOF)
                    return 0;                
                    
            } else if (c == '*')
            {
                do
                {
                    c = getchar();
                    if (c == '*')
                    {
                        if ((c = getchar()) != EOF)
                        {
                            if (c == '/')
                                break;
                        }
                    }
                } while (c != EOF);

                if (c == EOF)
                    return 0;
            } else
            {
                putchar('/');
                if (c == EOF)
                    return 0;
                else
                    putchar(c);
            }
        }
    }
    
    return 0;
}
//Comment #4

/* *Comment #5* */