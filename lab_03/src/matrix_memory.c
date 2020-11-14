#include "../inc/matrix_memory.h"

// Выделение обычной памяти
int common_memory_allocation(int x, int y, int ***matrix)
{
    // Код ошибки
    int error = OK;

    // Выделение памяти под массив указателей
    *matrix = malloc(sizeof(int *) * (size_t)x);
    if (*matrix == NULL)
    {
        error = MEMORY_ALLOCATION_ERROR;
    }

    // Выделение памяти под массивы элементов
    for (int i = 0; i < x && !error; i++)
    {
        (*matrix)[i] = malloc(sizeof(int) * (size_t)y);
        if ((*matrix)[i] == NULL)
        {
            error = MEMORY_ALLOCATION_ERROR;
        }
    }
    
    return error;
}

// Освобождение обычной матрицы
void common_memory_deallocation(int x, int ***matrix)
{
    if (*matrix != NULL)
    {
        // Освобождение элементов массива
        for (int i = 0; i < x; i++)
        {
            if ((*matrix)[i] != NULL)
            {
                free((*matrix)[i]);
                (*matrix)[i] = NULL;
            }
        }
    }

    // Освобождение массива указателей
    if (*matrix != NULL)
    {
        free(*matrix);
        *matrix = NULL;
    }
}

// Инициализация новой разреженной матрицы
void sparse_memory_allocation(sparse_matrix *smatrix)
{
    smatrix->A = malloc(sizeof(vector_t));
    smatrix->A->nums = NULL;
    smatrix->A->length = 0;
    smatrix->A->capacity = 0;
    
    smatrix->iA = malloc(sizeof(vector_t));
    smatrix->iA->nums = NULL;
    smatrix->iA->length = 0;
    smatrix->iA->capacity = 0;

    smatrix->jA = malloc(sizeof(list_t));
    smatrix->jA->begin = NULL;
    smatrix->jA->end = NULL;
    smatrix->jA->length = 0;
}

// Освобождение разреженной матрицы
void sparse_memory_deallocation(sparse_matrix *smatrix)
{
    vector_memory_deallocation(smatrix->A);
    vector_memory_deallocation(smatrix->iA);
    list_memory_deallocation(smatrix->jA);
}