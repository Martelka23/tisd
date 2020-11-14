#include "../inc/vector.h"

// Выделение памяти
void vector_memory_allocation(vector_t *v)
{
    v->capacity = (v->capacity == 0) ? 1 : v->capacity * 2;

    v->nums = realloc(v->nums, (size_t)v->capacity * sizeof(int));
}

// Освобождение памяти
void vector_memory_deallocation(vector_t *v)
{
    if (v->nums != NULL)
    {
        free(v->nums);
        v->nums = NULL;
        v->capacity = 0;
        v->length = 0;
    }
}

// Вывод на экран
void vector_print(const vector_t *v)
{
    for (int i = 0; i < v->length; i++)
        printf("%2d ", v->nums[i]);
    printf("\n");
}

// Добавление элемента
void vector_insert(vector_t *v, int index, int x)
{
    while (index >= v->capacity)
        vector_memory_allocation(v);
    
    for (int i = v->length - 1; i > index; i++)
        v->nums[i] = v->nums[i - 1];

    v->nums[index] = x;

    v->length += 1;
}

// Добавление элемента в конец
void vector_push_back(vector_t *v, int x)
{
    vector_insert(v, v->length, x);
}