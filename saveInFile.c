/*
    This program writes in a file called "test.txt" the output of a program

    For example:
        If you want to run ./Chapter1/Exercise1-18.sh and save the output,
        write in terminal the command:

            ./Chapter1/Exercise1-18.sh | ./saveInFile.sh 
*/

#include <stdio.h>

#define Error_Opening_File -1

int main()
{
    FILE* fp;
    int c;

    fp = fopen("test.txt", "w");
    if(fp == NULL)
        return Error_Opening_File;

    while ((c = getchar()) != EOF)
        fprintf(fp, "%c", c);

    fclose(fp);
    return 0;
}