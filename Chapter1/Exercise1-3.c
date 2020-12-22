/*
    Modify the temperature conversion program to print a heading above the table
*/

#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("---------------\n");
    printf("|  °F  |  °C  |\n");
    printf("---------------\n");
    while (fahr <= upper)
    {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("|%5.0f |%6.1f|\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("---------------\n");
}