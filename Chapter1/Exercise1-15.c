/*
    Rewrite the temperature conversion program of section 1.2 to use a function for conversion
*/

#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */

float fahrToCelsius(int fahrenheit);

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
        celsius = fahrToCelsius(fahr);
        printf("|%5.0f |%6.1f|\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("---------------\n");
}

float fahrToCelsius(int fahrenheit)
{
    float celsius;
    celsius = (5.0/9.0) * (fahrenheit-32.0);    
    return celsius;
}