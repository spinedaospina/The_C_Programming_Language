#include <stdio.h>

/* The character \c is unknow by gcc, For more info:
   https://stackoverflow.com/questions/34908971/c-escape-sequence-listed-in-man-but-unkown-in-c */

int main()
{
    printf("Hello, world \n");
    printf("\\\\Hello,\t world\\\\ \n");

    return 0;
}