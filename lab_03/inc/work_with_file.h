#pragma once

#include <time.h>

#include "matrix_io.h"
#include "matrix_memory.h"

// Считывание рамеров из файла
error_code matrix_read_size(FILE *file, common_matrix *matrix);
// Считывание элементов из файла
error_code matrix_read_elements(FILE *file, common_matrix *matrix);
// Считывание матрицы из файла
error_code matrix_read(common_matrix *matrix, char *name);
// Главная функция считывания из файла
error_code matrix_main_read(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    );
// Генерация случайного числа
int generate_random_num();
// Генерация матрицы в файле
error_code matrix_create(char *name);
// Главная функция генерации матрицы в файле
error_code matrix_main_create();