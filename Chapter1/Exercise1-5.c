#include <stdio.h>

/* 
   print Celsius-Fahrenheit table
   for celsius = 300, 280, ..., 0;
*/

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("---------------\n");
    printf("|  °C  |  °F  |\n");
    printf("---------------\n");

    for (celsius = upper; celsius >= lower; celsius = celsius - step)
    {
        fahr = (celsius*9/5)+32;
        printf("|%5.0f |%6.1f|\n", celsius, fahr);
    }

    printf("---------------\n");
}