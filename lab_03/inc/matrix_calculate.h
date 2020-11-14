#pragma once

#include <time.h>

#include "matrix_io.h"
#include "matrix_memory.h"

#define START_TIMER clock_t t; \
    t = clock();
#define END_TIMER t = clock() - t; \
    return ((double)t)/CLOCKS_PER_SEC;

// Сложение обычных матриц
double common_matrix_calculate(
    common_matrix *matrix1,
    common_matrix *matrix2,
    common_matrix *result
    );

// Разреженное сложение матриц
double sparse_matrix_calculate(
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2,
    sparse_matrix *sresult
    );

// Главная функция суммы матриц
error_code matrix_menu_calculate(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    );