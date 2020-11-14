#include "../inc/list_stack.h"


// Выделение памяти узла
void node_memory_allocation(node_t *node)
{
    node = calloc(1, sizeof(node_t));
}

// Конструктор
void list_stack_init(list_stack_t *list_stack)
{
    list_stack->begin = NULL;
    list_stack->end = NULL;
    list_stack->length = 0;
}

// Освобождение памяти узла
void node_memory_deallocation(node_t *node)
{
    free(node);
    node = NULL;
}

// Деструктор
void list_stack_del(list_stack_t *list_stack)
{
    while (list_stack->end != NULL)
    {
        node_t *tmp = list_stack->end;
        list_stack->end = list_stack->end->prev;
        node_memory_deallocation(tmp);
    }
}

// Добавление элемента
void list_stack_add(list_stack_t *list_stack)
{
    if (list_stack->begin == NULL)
    {
        node_memory_allocation(list_stack->begin);
        list_stack->end = list_stack->begin;
    } else
    {
        node_t *tmp = list_stack->end;
        list_stack->end = NULL;
        node_memory_allocation(list_stack->end);
        list_stack->end->prev = tmp;
    }
}

// Удаление элемента
error_code list_stack_pop(list_stack_t *list_stack, int *x)
{
    error_code error = (list_stack->end == NULL) ? STACK_UNDERFLOW : OK;

    if (!error)
    {
        *x = list_stack->end->num;
        node_t *tmp = list_stack->end->prev;
        node_memory_deallocation(list_stack->end);
        list_stack->end = tmp;
    }

    return error;
}