/*
    Write a program to check a C program for rudimentary syntax errors
    like unbalanced parentheses, brackets and braces. Don't forget about
    quotes, both singles and double, escape secuences, and comments. 
    (This program is hard if you do it in full generality.)
*/

#include <stdio.h>

#define MAXLINE 1000

#define PAIRED 0
#define UNPAIRED 1

#define NO 0

#define CODE 0
#define SHORTCOMMENT 1
#define LONGCOMMENT 2

// Give the length of the escape sequence (Due to some are bigger than 2 chars)
int checkIfIsAValidEscapeSequence(char array[], int position);

int get_line(char line[], int position);

int main()
{
    int length, actualPos, aux;
    char line[MAXLINE];

    int numberOfUnpairedParentheses = 0;    // Parentheses  == ()
    int numberOfUnpairedBrackets = 0;       //   Brackets   == []
    int numberOfUnpairedBraces = 0;         //    Braces    == {}
    int numberOfUnpairedComments = 0;       //   Comments   == /*   (The // can't be unpaired)
    int numberOfInvalidSequences = 0;       // Sequences listed in Section 2.3

    int stateOfDoubleQuote = PAIRED;        // Double Quote == "
    int stateOfSingleQuote = PAIRED;        // Single Quote == '
    int state = CODE;

    int isAValidSequence = NO;              // to works in escape sequence logic

    while ((length = get_line(line, MAXLINE)) > 0)
    {
        for(actualPos = 0; actualPos < length; ++actualPos)
        {
            if (state == SHORTCOMMENT)
                continue;
            else if (state == LONGCOMMENT)
            {
                if (line[actualPos] == '*' && line[actualPos+1] == '/')
                    state = CODE;
            } else if (state == CODE)
            {
                if (line[actualPos] == '\\')
                {
                    if ((aux = checkIfIsAValidEscapeSequence(line, actualPos+1)) != NO)
                    {
                        actualPos += aux;
                        continue;
                    } else
                    {
                        ++actualPos;
                        ++numberOfInvalidSequences;
                    }
                }

                //Balance of Parentheses
                if (line[actualPos] == '(')
                    ++numberOfUnpairedParentheses;

                else if (line[actualPos] == ')')
                    --numberOfUnpairedParentheses;

                //Balance of Brackets
                else if (line[actualPos] == '[')
                    ++numberOfUnpairedBrackets;

                else if (line[actualPos] == ']')
                    --numberOfUnpairedBrackets;

                //Balance of Braces
                else if (line[actualPos] == '{')
                    ++numberOfUnpairedBraces;

                else if (line[actualPos] == '}')
                    --numberOfUnpairedBraces;

                //Balance of Double Quotes
                else if (line[actualPos] == '\"')
                {
                    if (stateOfDoubleQuote == PAIRED)
                        stateOfDoubleQuote = UNPAIRED;
                    else
                        stateOfDoubleQuote = PAIRED;
                }

                //Balance of Single Quotes
                else if (line[actualPos] == '\'')
                {
                    if (stateOfSingleQuote == PAIRED)
                        stateOfSingleQuote = UNPAIRED;
                    else
                        stateOfSingleQuote = PAIRED;
                }
            
                // Comments
                else if (line[actualPos] == '/')
                {
                    if (line[actualPos+1] == '/')
                    {
                        state = SHORTCOMMENT;
                        printf("State changed to SHORTCOMMENT.\n");
                    }
                    else if (line[actualPos+1] == '*')
                    {
                        state = LONGCOMMENT;
                        printf("State changed to LONGCOMMENT.\n");
                    }
                }
            } else
            {
                printf("State != CODE, LONGCOMMENT, SHORTCOMMENT\n");
                return -1;
            }
        }

        if (state == SHORTCOMMENT)
            state = CODE;
              
    }

    //Check if everything is alright
    if (numberOfInvalidSequences == 0 && numberOfUnpairedBraces == 0 && numberOfUnpairedBrackets == 0 && numberOfUnpairedComments == 0 && numberOfUnpairedParentheses == 0 && stateOfDoubleQuote == PAIRED && stateOfSingleQuote == PAIRED)
    {
        printf("|--------------------------------------------|\n");
        printf("|          ¡Everything is alright!           |\n");
        printf("|--------------------------------------------|\n\n");
    }
    

    // Print the results
    printf("Number of Unpaired Parentheses: %d.\n", numberOfUnpairedParentheses);
    printf("Number of Unpaired Braces: %d.\n", numberOfUnpairedBraces);
    printf("Number of Unpaired Brackets: %d.\n", numberOfUnpairedBrackets);
    printf("Number of Unpaired Comments: %d.\n", numberOfUnpairedComments);
    printf("Number of Invalid Sequences: %d.\n", numberOfInvalidSequences);
    printf("\n");

    printf("Are double quotes paired?");
    if (stateOfDoubleQuote == PAIRED)
        printf(" YES.\n");
    else if (stateOfDoubleQuote == UNPAIRED)
        printf(" NO.\n");
    else
        printf(" IDK, WHY?!?!?!\n");
    
    printf("Are single quotes paired?");
    if (stateOfSingleQuote == PAIRED)
        printf(" YES.\n");
    else if (stateOfSingleQuote == UNPAIRED)
        printf(" NO.\n");
    else
        printf(" IDK, WHY?!?!?!\n");

    
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
            s[i] = c;
    }
    if (c == '\n') {        
        s[i] = c;
        ++i;
    }   
    s[i] = '\0';

    return i;
}

int checkIfIsAValidEscapeSequence(char array[], int position)
{
    switch (array[position])
    {
        case 'a':
            return 1;
            break;

        case 'b':
            return 1;
            break;

        case 'f':
            return 1;
            break;
        
        case 'n':
            return 1;
            break;
        
        case 'r':
            return 1;
            break;
        
        case 't':
            return 1;
            break;
        
        case 'v':
            return 1;
            break;
        
        case '\\':
            return 1;
            break;
        
        case '\?':
            return 1;
            break;
        
        case '\'':
            return 1;
            break;
        
        case '\"':
            return 1;
            break;
        
        case '0':
            return 1;
            break;
        
        case 'o':
            switch (array[position+1])
            {
                case 'o':
                    switch (array[position+2])
                    {
                        case 'o':
                            return 3;
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
            break;
        
        case 'x':
            switch (array[position+1])
            {
                case 'h':
                    switch (array[position+2])
                    {
                        case 'h':
                            return 3;
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
            break;
        
        default:
            break;
    }
    return NO;
}