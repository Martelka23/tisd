#pragma once
#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>


// Структура узла
typedef struct node
{
    int num;
    struct node *next;
} node_t;

// Структура списка
typedef struct list
{
    node_t *begin;
    node_t *end;
    int length;
} list_t;

// Выделение памяти
void list_memory_allocation(list_t *l);
// Освобождение памяти
void list_memory_deallocation(list_t *l);
// Вставка в конец
void list_push(list_t *l, int x);
// Вставка элемента
void list_insert(list_t *l, int index, int x);
// Замена элемента
void list_change_element(list_t *l, int index, int x);
// Вывод на экран
void list_print(list_t * const l);