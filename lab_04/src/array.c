#include "../inc/array.h"


// Выделение памяти под массив
void array_memory_allocation(array_t *array)
{
    array->nums = calloc(array->capacity, sizeof(int));
}

// Конструктор массива
error_code array_init(array_t *array, int new_capacity)
{
    error_code error = OK;

    if (new_capacity > 0)
    {
        array->capacity = new_capacity;
        array->length = 0;
        array_memory_allocation(array);
    } else
        error = WRONG_CAPACITY;

    return error;
}

// Отчищение памяти
void array_memory_deallocation(array_t *array)
{
    free(array->nums);
    array->nums = NULL;
}

// Деструктор массива
void array_del(array_t *array)
{
    array->capacity = 0;
    array->length = 0;
    array_memory_deallocation(array);
}

// Вставка элемента в конец массива
error_code array_push_back(array_t *array, int x)
{
    error_code error = OK;

    if (array->length <= array->capacity)
    {
        array->nums[array->length] = x;
        array->length += 1;
    }
    else
        error = ARRAY_OWERFLOW;

    return error;
}

// Считывание элемента из конца массива
const int *array_get_last_element(const array_t *array)
{
    return (array->length > 0) ? array->nums[array->length - 1] : NULL;
}

// Удаление элемента из конца массива
error_code array_remove_last_element(array_t *array)
{
    error_code error = OK;

    if (array->length > 0)
        array->length -= 1;
    else
        error = ARRAY_UNDERFLOW;

    return error;
}

// Удаление и возврат элемента из конца массива
int *array_pop(array_t *array)
{
    error_code error = OK;
    int *result;

    if (array->length > 0)
    {
        result = *array_get_last_element(array);
        array_remove_last_element(array);
    } else
        error = ARRAY_UNDERFLOW;

    return (error) ? NULL : result;
}

// Считывание элементов массива по указателям
void array_print(const int *begin, const int *end)
{
    int step = (begin < end) ? 1 : -1;

    for (const int *p = begin; p != end; p += step)
        printf("%d ", *p);
}