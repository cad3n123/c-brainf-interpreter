#include <stdio.h>
#include <stdlib.h> // For exiting
#include <string.h> // For memset
#include <signal.h>
#include "cross_input.h"
#include "stack_template.h"

DECLARE_STACK(Int, int);

int main()
{
    char bytes[100];
    memset(bytes, 0, sizeof(bytes));
    char *pointer = bytes;
    IntStack bracket_stack;
    if (!Int_initializeStack(&bracket_stack))
    {
        printf("Unable to initialize stack");
        exit(0);
    }

    // ############
    // pointer++;
    // (*pointer) += 65;
    // printf("%c", *pointer);
    // ############

    //                  0123456789
    char inputCode[] = ",[.,]"; //"++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    /*
               v
    stack = 1, 3
    Stack:
        push
        pop
        peek
    */
    for (size_t i = 0; i < sizeof(inputCode); i++)
    {
        char c = inputCode[i];

        switch (c)
        {
        case '+':
            (*pointer)++;
            break;
        case '-':
            (*pointer)--;
            break;
        case '>':
            pointer++;
            break;
        case '<':
            pointer--;
            break;
        case '.':
            printf("%c", *pointer);
            break;
        case ',':
            *pointer = get_char();
            break;
        case '[':
            Int_push(&bracket_stack, i);
            break;
        case ']':
            if (*pointer != 0)
            {
                i = Int_peek(&bracket_stack);
            }
            else
            {
                Int_pop(&bracket_stack);
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
