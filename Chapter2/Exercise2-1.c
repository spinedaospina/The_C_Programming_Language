/*
    Write a program to determine the ranges of chart, short, int,
    and long variables, both signed and unsigned, by printing appropiate values
    from standar headers and by direct computation. Harder if you compute them:
    determine the ranges of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(int argc, char const *argv[])
{
    /* With <limits.h> */
    printf("\n\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|                          Using limits.h                          |\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|          |          Signed           |         Unsigned          |\n");
    printf("|   Type   |     Max     |     Min     |     Max     |     Min     |\n");
    printf("|------------------------------------------------------------------|\n");

    printf("|   Char   |%13d|%13d|%13d|%13d|\n", SCHAR_MAX, SCHAR_MIN, UCHAR_MAX, 0);
    printf("|   Short  |%13d|%13d|%13d|%13d|\n", SHRT_MAX, SHRT_MIN, USHRT_MAX, 0);
    printf("|   Int    |%13d|%13d|%13d|%13d|\n", INT_MAX, INT_MIN, UINT_MAX, 0);

    if (LONG_MAX == 9223372036854775807)
        printf("|   Long   |%13ld|%13ld|%6ld|%7d|\n", LONG_MAX, LONG_MIN, ULONG_MAX, 0);
    else
        printf("|   Long   |%13ld|%13ld|%13ld|%13d|\n", LONG_MAX, LONG_MIN, ULONG_MAX, 0);
        
    printf("|   float  |10^%10d|10^%10d|      -      |      -      |\n", FLT_MAX_10_EXP, FLT_MIN_10_EXP);
    printf("|  doubleF |10^%10d|10^%10d|      -      |      -      |\n", DBL_MAX_10_EXP, DBL_MIN_10_EXP);
    
    printf("|------------------------------------------------------------------|\n");
    printf("\n\n");


    return 0;
}