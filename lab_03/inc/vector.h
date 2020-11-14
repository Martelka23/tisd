#pragma once
#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>

typedef struct vector_t
{
    int *nums;
    int length;
    int capacity;
} vector_t;


// Выделение памяти
void vector_memory_allocation(vector_t *v);
// Освобождение памяти
void vector_memory_deallocation(vector_t *v);
// Вывод на экран
void vector_print(const vector_t *v);
// Добавление элемента
void vector_insert(vector_t *v, int index, int x);
// Добавление элемента в конец
void vector_push_back(vector_t *v, int x);