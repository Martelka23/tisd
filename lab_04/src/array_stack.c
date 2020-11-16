#include "../inc/array_stack.h"


// Выделение памяти
void array_stack_memory_allocation(array_stack_t *array_stack)
{
    array_stack->begin = calloc((size_t)array_stack->capacity, sizeof(int));
}

// Конструктор
void array_stack_init(array_stack_t *array_stack)
{
    array_stack->begin = NULL;
    array_stack->end = NULL;
    array_stack->capacity = 5;
    array_stack_memory_allocation(array_stack);
    array_stack->end = array_stack->begin;
}

// Освобождение памяти
void array_stack_memory_deallocation(array_stack_t *array_stack)
{
    free(array_stack->begin);
}

// Деструктор
void array_stack_del(array_stack_t *array_stack)
{
    array_stack_memory_deallocation(array_stack);
    array_stack->begin = NULL;
    array_stack->end = NULL;
    array_stack->capacity = 0;
}

// Добавление элемента
error_code array_stack_add(array_stack_t *array_stack, int x)
{
    error_code error = (array_stack->end - array_stack->begin >= array_stack->capacity) ? STACK_OWERFLOW : OK;

    if (!error)
    {
        *array_stack->end = x;
        array_stack->end++;
    }

    return error;
}

// Удаление элемента
error_code array_stack_pop(array_stack_t *array_stack, int *x)
{
    error_code error = (array_stack->begin == array_stack->end) ? STACK_UNDERFLOW : OK;

    if (!error)
    {
        array_stack->end--;
        *x = *array_stack->end;
    }

    return error;
}