#pragma once
#pragma pack (1)

#include <stdio.h>
#include <stdlib.h>

#include "errors.h"


// Структура стэка на массиве
typedef struct array_stack
{
    int *begin;
    int *end;
    int capacity;
} array_stack_t;


// Выделение памяти
void array_stack_memory_allocation(array_stack_t *array_stack);
// Конструктор
void array_stack_init(array_stack_t *array_stack);
// Освобождение памяти
void array_stack_memory_deallocation(array_stack_t *array_stack);
// Деструктор
void array_stack_del(array_stack_t *array_stack);
// Добавление элемента
error_code array_stack_add(array_stack_t *array_stack, int x);
// Удаление элемента
error_code array_stack_pop(array_stack_t *array_stack, int *x);