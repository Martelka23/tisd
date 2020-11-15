#pragma once
#pragma pack (1)

#include <stdlib.h>

#include "errors.h"


// Узел списка
typedef struct node
{
    int num;
    struct node *prev;
} node_t;

// Структура стэка на списке
typedef struct list_stack
{
    node_t *begin;
    node_t *end;
    int length;
} list_stack_t;


// Выделение памяти узла
void node_memory_allocation(node_t **node);
// Конструктор
void list_stack_init(list_stack_t *list_stack);
// Освобождение памяти узла
void node_memory_deallocation(node_t **node);
// Деструктор
void list_stack_del(list_stack_t *list_stack);
// Добавление элемента
void list_stack_add(list_stack_t *list_stack, int x);
// Удаление элемента
error_code list_stack_pop(list_stack_t *list_stack, int *x);