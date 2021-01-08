/*
    Write a loop equivalent to the for
    loop above without using && or ||
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    int i, lim;

    while (i<lim-1)
    {
        c = getchar();
        if (c == '\n')
            break;
        else if (c == EOF)
            break;
        
        /*code*/
    }
    
    return 0;
}
