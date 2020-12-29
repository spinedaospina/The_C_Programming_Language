/*
    Write a program to check a C program for rudimentary syntax errors
    like unbalanced parentheses, brackets and braces. Don't forget about
    quotes, both singles and double, escape secuences, and comments. 
    (This program is hard if you do it in full generality.)
*/

#include <stdio.h>

#define UNPAIRED 1
#define PAIRED 0

#define NO 0
#define YES 1
#define BREAK 2

int checkIfIsAValidEscapeSequence(char character);

int main()
{
    int c;

    int numberOfUnpairedParentheses = 0;    // Parentheses  == ()
    int numberOfUnpairedBrackets = 0;       //   Brackets   == []
    int numberOfUnpairedBraces = 0;         //    Braces    == {}
    int numberOfUnpairedComments = 0;       //   Comments   == /* (The // can't be unpaired)
    int numberOfInvalidSequences = 0;       // Sequences listed in Section 2.3

    int stateOfDoubleQuote = PAIRED;        // Double Quote == "
    int stateOfSingleQuote = PAIRED;        // Single Quote == '

    int needToBrake = NO;                   // to works in comment's logic
    int isAValidSequence = NO;              // to works in escape sequence logic


    // Read the file and get results
    while ((c=getchar()) != EOF)
    {
        switch (c)
        {
            //Balance of Parentheses
            case '(':
                ++numberOfUnpairedParentheses;
                break;

            case ')':
                --numberOfUnpairedParentheses;
                break;


            //Balance of Brackets
            case '[':
                ++numberOfUnpairedBrackets;
                break;

            case ']':
                --numberOfUnpairedBrackets;
                break;


            //Balance of Braces
            case '{':
                ++numberOfUnpairedBraces;
                break;

            case '}':
                --numberOfUnpairedBraces;
                break;


            //Balance of Double Quotes
            case '\"':
                if (stateOfDoubleQuote == PAIRED)
                    stateOfDoubleQuote = UNPAIRED;
                else
                    stateOfDoubleQuote = PAIRED;
                break;

            //Balance of Single Quotes
            case '\'':
                if (stateOfSingleQuote == PAIRED)
                    stateOfSingleQuote = UNPAIRED;
                else
                    stateOfSingleQuote = PAIRED;
                break;
            

            //Balance of Comments
            case '/':
                c = getchar();
                switch (c)
                {
                    case '*':
                        ++numberOfUnpairedComments;
                        break;
                    case EOF:
                        needToBrake = YES;
                    default:
                        break;
                }
                break;
            
            case '*':
                c = getchar();
                switch (c)
                {
                    case '/':
                        --numberOfUnpairedComments;
                        break;
                    case EOF:
                        needToBrake = YES;
                    default:
                        break;
                }
                break;


            //Balance of escape sequences
            case '\\':
                c = getchar();
                isAValidSequence = checkIfIsAValidEscapeSequence(c);
                if (isAValidSequence == NO)
                {
                    ++numberOfInvalidSequences;
                }
                

            default:
                break;
        }

        if (needToBrake == YES || isAValidSequence == BREAK)
            break;   
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

int checkIfIsAValidEscapeSequence(char c)
{
    switch (c)
    {
        case EOF:
            return BREAK;
            break;

        case 'a':
            return YES;
            break;

        case 'b':
            return YES;
            break;

        case 'f':
            return YES;
            break;
        
        case 'n':
            return YES;
            break;
        
        case 'r':
            return YES;
            break;
        
        case 't':
            return YES;
            break;
        
        case 'v':
            return YES;
            break;
        
        case '\\':
            return YES;
            break;
        
        case '\?':
            return YES;
            break;
        
        case '\'':
            return YES;
            break;
        
        case '\"':
            return YES;
            break;
        
        case 'o':
            c = getchar();
            switch (c)
            {
                case EOF:
                    return BREAK;

                case 'o':
                    c = getchar();
                    switch (c)
                    {
                        case EOF:
                            return BREAK;

                        case 'o':
                            return YES;
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
            c = getchar();
            switch (c)
            {
                case EOF:
                    return BREAK;

                case 'h':
                    c = getchar();
                    switch (c)
                    {
                        case EOF:
                            return BREAK;

                        case 'h':
                            return YES;
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