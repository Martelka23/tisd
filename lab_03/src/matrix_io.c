#include "../inc/matrix_io.h"

// Ввод размера матрицы
error_code input_size(int *x, int *y)
{
    error_code error = OK;

    if (scanf("%d%d", x, y) != 2 || *x <= 0 || *y <= 0)
    {
        error = SIZE_ERROR;
    }

    return error;
}

// Ввод элемента
error_code input_element(int *x)
{
    error_code error = OK;
    if (!scanf("%d", x))
    {
        error = INPUT_ERROR;
    }

    return error;
}

// Ввод обычной матрицы
error_code input_matrix(int x, int y, int ***matrix)
{
    // Код ошибки
    error_code error = OK;

    // Выделение памяти
    error = common_memory_allocation(x, y, matrix);

    // Ввод значений
    if (!error)
        for (int i = 0; i < x && !error; i++)
            for (int j = 0; j < y && !error; j++)
                error = input_element(&(*matrix)[i][j]);

    return error;
}

// Ввод обычных начальных данных
error_code common_matrix_input(common_matrix *matrix1, common_matrix *matrix2)
{
    // Код ошибки
    error_code error = OK;

    // Ввод матрицы А
    printf("Введите размеры матрицы 1 >>> ");
    error = input_size(&matrix1->m, &matrix1->n);
    if (!error)
    {
        printf("Введите элементы матрицы 1:\n");
        error = input_matrix(matrix1->m, matrix1->n, &matrix1->M);
    }

    // Ввод матрицы В
    if (!error)
    {
        printf("Введите размеры матрицы 2 >>> ");
        error = input_size(&matrix2->m, &matrix2->n);
    }
    if (!error)
    {
        printf("Введите элементы матрицы 2:\n");
        error = input_matrix(matrix1->m, matrix2->n, &matrix2->M);
    }

    return error;
}

// Вывод обычной матрицы на экран
void common_matrix_output(common_matrix *matrix)
{
    for (int i = 0; i < matrix->m; i++)
    {
        printf("%3d", matrix->M[i][0]);
        for (int j = 1; j < matrix->n; j++)
            printf(" %3d", matrix->M[i][j]);
        printf("\n");
    }
}

// Ввод разреженных матриц
error_code a_ia_ja_input(sparse_matrix *smatrix, int z, int y, int x)
{
    error_code error = OK;

    printf(" A = ");
    for (int i = 0; i < z && !error; i++)
    {
        int num;
        if (!scanf("%d", &num))
            error = INPUT_ERROR;
        else
            vector_push_back(smatrix->A, num);
    }
    printf("iA = ");
    for (int i = 0; i < z && !error; i++)
    {
        int num;
        if (!scanf("%d", &num))
            error = INPUT_ERROR;
        else if (num < 0 || num > x)
            error = INDEX_ERROR;
        else
            vector_push_back(smatrix->iA, num);
    }
    printf("jA = ");
    for (int i = 0; i < y && !error; i++)
    {
        int num;
        if (!scanf("%d", &num))
            error = INPUT_ERROR;
        else if (num < 0 || num > z)
            error = INDEX_ERROR;
        else
            list_push(smatrix->jA, num);
    }

    return error;
}

// Вывод разреженной матрицы
void sparse_matrix_output(sparse_matrix *smatrix)
{
    printf("    ");
    for (int i = 0; i < smatrix->A->length; i++)
        printf(" %2d", i);
    printf("\n A = ");
    vector_print(smatrix->A);
    printf("iA = ");
    vector_print(smatrix->iA);
    printf("jA = ");
    list_print(smatrix->jA);
}

// Ввод разреженных начальных данных
error_code sparse_matrix_input(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    )
{
    // Код ошибки
    error_code error = OK;

    printf("\n***Ввод разреженной матрицы***\n");

    // Размеры
    int x, y;

    // Ввод матрицы А
    printf("Введите размеры матрицы 1 >>> ");
    error = input_size(&x, &y);
    if (!error)
    {
        matrix1->m = x;
        matrix1->n = y;
        printf("Введите количество ненулевых элементов >>> ");
        scanf("%d", &x);
        if (x > matrix1->m * matrix1->n)
            error = WRONG_ELEMENTS_COUNT;
    }
    if (!error)
        error = a_ia_ja_input(smatrix1, x, y, matrix1->m);

    // Ввод матрицы B
    if (!error)
    {
        printf("Введите размеры матрицы 2 >>> ");
        error = input_size(&x, &y);
        matrix2->m = x;
        matrix2->n = y;
    }
    if (!error)
    {
        printf("Введите количество ненулевых элементов >>> ");
        scanf("%d", &x);
        if (x > matrix1->m * matrix1->n)
            error = WRONG_ELEMENTS_COUNT;
    }
    if (!error)
        error = a_ia_ja_input(smatrix2, x, y, matrix2->m);

    return error;
}

// Конвертирование из разреженной матрицы в обычную
void sparse_in_common(sparse_matrix *smatrix, common_matrix *matrix)
{
    common_memory_deallocation(matrix->m, &matrix->M);
    common_memory_allocation(matrix->m, matrix->n, &matrix->M);
    for (int i = 0; i < matrix->m; i++)
        for (int j = 0; j < matrix->n; j++)
            matrix->M[i][j] = 0;   

    node_t *nnum = smatrix->jA->begin;
    int j = 0;
    for (int k = 0; k < smatrix->A->length; k++)
    {
        while (nnum->next != NULL && k == nnum->next->num)
        {
            nnum = nnum->next;
            j++;
        }
        matrix->M[smatrix->iA->nums[k]][j] = smatrix->A->nums[k];
    }
}

// Конвертация из обычной матрицы в разреженную
void common_in_sparse(common_matrix *matrix, sparse_matrix *smatrix)
{
    sparse_memory_deallocation(smatrix);
    for (int j = 0; j < matrix->n; j++)
    {
        int once = 0;
        for (int i = 0; i < matrix->m; i++)
        {
            if (matrix->M[i][j] != 0)
            {
                vector_push_back(smatrix->A, matrix->M[i][j]);
                vector_push_back(smatrix->iA, i);
                if (smatrix->jA->end == NULL || (smatrix->jA->end->num != smatrix->A->length - 1 && !once))
                {
                    once = 1;
                    while (smatrix->jA->length <= j)
                        list_push(smatrix->jA, smatrix->A->length - 1);
                }
            }
        }
    }
}

// Меню ввода
error_code matrix_input_menu(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    )
{
    error_code error = OK;

    int choise;

    print_matrix_input_interface();
    scanf("%d", &choise);

    if (choise == 1)
    {
        error = common_matrix_input(matrix1, matrix2);
        if (!error)
        {
            common_in_sparse(matrix1, smatrix1);
            common_in_sparse(matrix2, smatrix2);
        }
    }
    else if (choise == 2)
    {
        error = sparse_matrix_input(matrix1, matrix2, smatrix1, smatrix2);
        if (!error)
        {
            sparse_in_common(smatrix1, matrix1);
            sparse_in_common(smatrix2, matrix2);
        }
    }
    else
        printf("Неизвестная команда!\n");

    return error;
}

// Меню вывода
void matrix_output_menu(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    )
{
    int choise;

    print_matrix_output_interface();
    scanf("%d", &choise);

    if (choise == 1)
    {
        printf("\n***Обычный формат вывода***\n");
        printf("#Матрица 1\n");
        common_matrix_output(matrix1);
        printf("#Матрица 2\n");
        common_matrix_output(matrix2);
    }
    else if (choise == 2)
    {
        printf("\n***Разреженный формат вывода***\n");
        printf("#Матрица 1\n");
        sparse_matrix_output(smatrix1);
        printf("#Матрица 2\n");
        sparse_matrix_output(smatrix2);
    }
}