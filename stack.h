#pragma once

#include <stdbool.h> // For bool
#include <stddef.h>  // For size_t

#define TYPE int

typedef struct Stack
{
    TYPE *start;
    size_t length;
    size_t capacity;
} Stack;

bool initializeStack(Stack *stack);
bool push(Stack *stack, TYPE value);
TYPE pop(Stack *stack);
TYPE peek(const Stack *stack);
