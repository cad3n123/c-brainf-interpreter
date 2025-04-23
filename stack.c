#include "stack.h"
#include <stdlib.h> // For memory allocation

bool initializeStack(Stack *stack)
{
    stack->capacity = 10;
    TYPE *start = (TYPE *)malloc(stack->capacity); // Creates stack on heap, because it grows dynamically (changes size at run time, we dont know how big it'll be)
    // If allocation failed, lets let the caller know by returning false
    if (start == NULL)
        return false;
    stack->start = start;
    stack->length = 0;
    // Return true to let the caller know that the stack was successfully initialized
    return true;
}

bool push(Stack *stack, TYPE value)
{
    // If the stack is full, we need to allocate more memory. We'll just double the size
    if (stack->length == stack->capacity)
    {
        size_t new_capacity = stack->capacity * 2;
        TYPE *newStart = (TYPE *)realloc(stack->start, new_capacity);
        // If reallocation failed, the stack is still safe. But lets let the caller know by returning false
        if (newStart == NULL)
            return false;
        stack->capacity = new_capacity;
    }
    // If the stack isn't full, or now has enough capacity, we add the item to the end
    *(stack->start + stack->length) = value;
    stack->length++;
    // Return true to let the caller know that the item was successfully added
    return true;
}

TYPE pop(Stack *stack)
{
    stack->length--;
    return stack->start[stack->length];
}

TYPE peek(const Stack *stack)
{
    return stack->start[stack->length - 1];
}
