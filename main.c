#include <stdio.h>
#include <stdlib.h> // For exiting
#include <string.h> // For memset
#include "stack.h"

int main()
{
    char bytes[100];
    memset(bytes, 0, sizeof(bytes));
    char *pointer = bytes;
    Stack stack;
    if (!initializeStack(&stack))
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
    char inputCode[] = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    /*
               v
    stack = 1, 3
    Stack:
        push
        pop
        peek
    */
    for (int i = 0; i < sizeof(inputCode); i++)
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
        case '[':
            push(&stack, i);
            break;
        case ']':
            if (*pointer != 0)
            {
                i = peek(&stack);
            }
            else
            {
                pop(&stack);
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
