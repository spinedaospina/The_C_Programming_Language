/*
    Write a program to print a histogram of the lengths of words in its input.
    It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#include <stdio.h>

#define IN 0
#define OUT 1

void printHistogram(int array[], int maxLength);

int main()
{
    int c, actualLength, lastState, state, maxLength;

    state = lastState = OUT;
    actualLength = 0;
    maxLength = 50;

    int array[maxLength];

    for (int i = 0; i < maxLength; ++i)
        array[i] = 0;
    
    printf("Write a short paragraph without words with more than 49 characters:\n\n");

    while ((c=getchar()) != EOF)
    {
        // Check state (IN a word or OUT a word)
        if (c == ' ' || c == '\n' || c == '\t') 
            state = OUT;
        else if (state == OUT)
            state = IN;

        // Check if enter, stay or exit a word
        //              Enter                 ||             stay               ||
        if ((state == IN && lastState == OUT) || (state == IN && lastState == IN))
            ++actualLength;
        
        // Exit the word
        else
        {
            ++array[actualLength];
            actualLength = 0;
        }

        lastState = state;
    }

    // Reduce the length of the array
    for (int i = maxLength-1; i >= 0; i--)
    {
        if (array[i] != 0)
        {
            maxLength = i;
            break;
        }
    }

    printHistogram(array, maxLength);

    return 0;
}

void printHistogram(int array[], int maxLength)
{
    // The words with 0 characters like ' ', '\t', etc, are not printed

    // Horizontal histogram

    printf("\n\n");
    printf("|------------------------------------------------|\n");
    printf("| Histogram of the lengths of words (Horizontal) |\n");
    printf("|------------------------------------------------|\n");
    for (int i = 1; i <= maxLength; i++)    // Remember, maxLength has another meaning in this function
    {
        printf("%2d: ", i);
        for (int j = 0; j < array[i]; j++)
            printf("#");
        printf("\n");
    }
    
    // Vertical histogram
    printf("\n\n");
    printf("|----------------------------------------------|\n");
    printf("| Histogram of the lengths of words (Vertical) |\n");
    printf("|----------------------------------------------|\n");

    // Check Max value in array[]
    int max = array[1];

    for (int i = 2; i <= maxLength; i++)
    {
        if (max < array[i])
            max = array[i];
    }

    // Write "#"
    for (int i = 0; i < max;)
    {
        for (int j = 1; j <= maxLength; j++)
        {
            if(array[j] >= max)
                printf("  #");
            else
                printf("   ");
        }
        printf("\n");
        --max;
    }
    
    // Draw Footer
    for(int i = 1; i<= maxLength; i++)
        printf("%3d", i);
    printf("\n");
}