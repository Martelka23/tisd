#pragma once

#include "matrix.h"
#include "matrix_memory.h"

// Ввод размера матрицы
error_code input_size(int *x, int *y);
// Ввод элемента
error_code input_element(int *x);
// Ввод обычной матрицы
error_code input_matrix(int x, int y, int ***matrix);
// Ввод обычных начальных данных
error_code common_matrix_input(common_matrix *matrix1, common_matrix *matrix2);
// Вывод обычной матрицы на экран
void common_matrix_output(common_matrix *matrix);
// Ввод разреженных матриц
error_code a_ia_ja_input(sparse_matrix *smatrix, int z, int y, int x);
// Вывод разреженной матрицы
void sparse_matrix_output(sparse_matrix *smatrix);
// Ввод разреженных начальных данных
error_code sparse_matrix_input(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    );
// Конвертирование из разреженной матрицы в обычную
void sparse_in_common(sparse_matrix *smatrix, common_matrix *matrix);
// Конвертация из обычной матрицы в разреженную
void common_in_sparse(common_matrix *matrix, sparse_matrix *smatrix);
// Меню ввода
error_code matrix_input_menu(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    );
// Меню вывода
void matrix_output_menu(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    );