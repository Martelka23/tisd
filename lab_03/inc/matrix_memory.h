#pragma once

#include "matrix.h"
#include "errors.h"
#include "vector.h"
#include "list.h"

// Выделение обычной памяти
int common_memory_allocation(int x, int y, int ***matrix);
// Освобождение обычной матрицы
void common_memory_deallocation(int x, int ***matrix);
// Освобождение разреженной матрицы
void sparse_memory_deallocation(sparse_matrix *smatrix);
// Инициализация новой разреженной матрицы
void sparse_memory_allocation(sparse_matrix *smatrix);