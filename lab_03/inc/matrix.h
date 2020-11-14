#pragma once
#pragma pack(1)

#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "errors.h"
#include "vector.h"
#include "interface.h"


// Структура обычной матрицы
typedef struct
{
    int **M;
    int m;
    int n;
} common_matrix;

// Структура разреженной матрицы
typedef struct
{
    vector_t *A;
    vector_t *iA;
    list_t *jA;
} sparse_matrix;
