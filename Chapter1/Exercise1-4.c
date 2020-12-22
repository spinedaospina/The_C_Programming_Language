/*
    Write a program to print the corresponding Celsius to Fahrenheit table.
*/

#include <stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = 0, 20, ..., 300; floating-point version */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("---------------\n");
    printf("|  °C  |  °F  |\n");
    printf("---------------\n");
    while (celsius <= upper)
    {
        /* 
           If you use the expression fahr = (celsius*(9/5))+32;
           with parenthesis in "(9/5)", the results are bad
           C take the solution to (9/5) = 1, it eliminates the remainder
        */
        fahr = (celsius*9/5)+32;
        printf("|%5.0f |%6.1f|\n", celsius, fahr);
        celsius = celsius + step;
    }
    printf("---------------\n");
}