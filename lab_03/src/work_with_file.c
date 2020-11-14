#include "../inc/work_with_file.h"

// Считывание рамеров из файла
error_code matrix_read_size(FILE *file, common_matrix *matrix)
{
    return (fscanf(file, "%d%d\n", &matrix->m, &matrix->n) != 2 || matrix->m < 1 || matrix->n < 1) ? SIZE_ERROR : OK;
}

// Считывание элементов из файла
error_code matrix_read_elements(FILE *file, common_matrix *matrix)
{
    error_code error = OK;

    error = common_memory_allocation(matrix->m, matrix->n, &matrix->M);

    if (!error)
        for (int i = 0; i < matrix->m; i++)
            for (int j = 0; j < matrix->n; j++)
                if (fscanf(file, "%d", &matrix->M[i][j]) != 1)
                    error = INPUT_ERROR;

    return error;
}

// Считывание матрицы из файла
error_code matrix_read(common_matrix *matrix, char *name)
{
    // Код ошибки
    error_code error = OK;

    // Открытие файла
    FILE *file = fopen(name, "r");
    if (file == NULL)
        error = OPEN_ERROR;

    // Считывание размеров
    if (!error)
        error = matrix_read_size(file, matrix);

    // Считывание элементов
    if (!error)
        error = matrix_read_elements(file, matrix);

    // Закрытие файла
    if (error != OPEN_ERROR)
        fclose(file);

    return error;
}

// Главная функция считывания из файла
error_code matrix_main_read(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    )
{
    // Код ошибки
    error_code error = OK;

    // Считывание матрицы А
    error = matrix_read(matrix1, "./tests/input_1.txt");
    // Конвертирование матрицы А
    if (!error)
        common_in_sparse(matrix1, smatrix1);
    printf("Матрица 1 считана\n");

    // Считывание матрицы В
    if (!error)
        error = matrix_read(matrix2, "./tests/input_2.txt");
    // Конвертирование матрицы B
    if (!error)
        common_in_sparse(matrix2, smatrix2);
    printf("Матрица 2 считана\n");

    return error;
}

// Генерация случайного числа
int generate_random_num()
{
    // Генерация
    int from = -9;
    int to = 9;
    int x = rand() % (to - from + 1) + from;
    if (x > 9 || x < -9)
        x = 0;

    return x;
}

// Генерация матрицы в файле
error_code matrix_create(char *name)
{
    // Код ошибки
    error_code error = OK;

    // Сид
    srand((unsigned)time(NULL));

    // Ввод размеров матрицы
    int x, y;
    printf("Введите размеры матрицы >>> ");
    if (scanf("%d%d", &x, &y) != 2 || x < 1 || y < 1)
        error = SIZE_ERROR;

    // Генерация матрицы
    if (!error)
    {
        // Открытие файла
        FILE *file = fopen(name, "w");
        if (file == NULL)
            error = OPEN_ERROR;

        // Заполнение размеров
        if (!error)
            fprintf(file, "%d %d\n", x, y);

        // Заполнение элементов
        if (!error)
            for (int i = 0; i < x; i++)
            { 
                fprintf(file, "%d", generate_random_num());
                for (int j = 0; j < y; j++)
                    fprintf(file, " %d", generate_random_num());
                fprintf(file, "\n");
            }

        // Закрытие фала
        if (error != OPEN_ERROR)
            fclose(file);
    }

    if (!error)
        printf("Матрица сгенерирована\n");

    return error;
}

// Главная функция генерации матрицы в файле
error_code matrix_main_create()
{
    // Код ошибки
    error_code error = OK;

    // Генерация матрицы А
    error = matrix_create("./tests/input_1.txt");

    // Генерация матрицы В
    if (!error)
        error = matrix_create("./tests/input_2.txt");

    return error;
}