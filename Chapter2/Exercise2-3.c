/*
    Write a function htoi(s), which converts a string of hexadecimal
    digits (including an optional 0x or 0X) into its equivalent integer value.
    The allowable digits are 0 through 9, a through f, and A through F.
*/

/*
    To compile:
        gcc Exercise2-3.c -o Exercise2-3.sh -lm
    
    Add d¿the "-lm" at the end
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLENGTH 100

#define YES 1
#define NO 0

int htoi(char string[]);

int main()
{
    char c, hex[MAXLENGTH];
    int i = 0;
    int dec;
    int isHex = NO;

    printf("Write a hex number to convert it to decimal\n");

    while ((c = getchar()) != EOF &&  c != '\n')
    {
        if (c >= 'a' && c <= 'f')
            isHex = YES;
        else if (c >= 'A' && c <= 'F')
            isHex = YES;
        else if (c >= '0' && c <= '9')
            isHex = YES;
        
        if (isHex == NO)
        {
            printf("Write a correct hex number\n");
            continue;
        }
        
        hex[i] = c;
        i++;
        isHex = NO;
    }

    dec = htoi(hex);
    
    printf("The hex number: ");

    for (int i = 0; i < strlen(hex); i++)
        putchar(hex[i]);

    printf(" in decimal is: %d\n\n", dec);

    return 0;
}

int htoi(char hex[])
{
    int length = strlen(hex);
    int dec = 0, aux;
    for (int i = 0; i < length; i++)
    {
        aux = hex[i];

        if (aux >= 'a' && aux <= 'f')
            aux = hex[i] - 'a' + 10;
        else if (aux >= 'A' && aux <= 'F')
            aux = hex[i] - 'A' + 10;
        else if (aux >= '0' && aux <= '9')
            aux = hex[i] - '0';

        dec = aux * pow(16,(length-i-1)) + dec;
    }
    
    return dec;    
}