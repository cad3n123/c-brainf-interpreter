#pragma once
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#define DECLARE_STACK(NAME, TYPE)                                                        \
    typedef struct NAME##Stack                                                           \
    {                                                                                    \
        TYPE *start;                                                                     \
        size_t length;                                                                   \
        size_t capacity;                                                                 \
    } NAME##Stack;                                                                       \
                                                                                         \
    bool NAME##_initializeStack(NAME##Stack *stack)                                      \
    {                                                                                    \
        stack->capacity = 10;                                                            \
        stack->start = (TYPE *)malloc(stack->capacity * sizeof(TYPE));                   \
        if (stack->start == NULL)                                                        \
            return false;                                                                \
        stack->length = 0;                                                               \
        return true;                                                                     \
    }                                                                                    \
                                                                                         \
    bool NAME##_push(NAME##Stack *stack, TYPE value)                                     \
    {                                                                                    \
        if (stack->length == stack->capacity)                                            \
        {                                                                                \
            size_t new_capacity = stack->capacity * 2;                                   \
            TYPE *newStart = (TYPE *)realloc(stack->start, new_capacity * sizeof(TYPE)); \
            if (newStart == NULL)                                                        \
                return false;                                                            \
            stack->start = newStart;                                                     \
            stack->capacity = new_capacity;                                              \
        }                                                                                \
        stack->start[stack->length++] = value;                                           \
        return true;                                                                     \
    }                                                                                    \
                                                                                         \
    TYPE NAME##_pop(NAME##Stack *stack)                                                  \
    {                                                                                    \
        return stack->start[--stack->length];                                            \
    }                                                                                    \
                                                                                         \
    TYPE NAME##_peek(const NAME##Stack *stack)                                           \
    {                                                                                    \
        return stack->start[stack->length - 1];                                          \
    }
