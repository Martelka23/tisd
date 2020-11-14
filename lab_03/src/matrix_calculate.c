#include "../inc/matrix_calculate.h"



// Сложение обычных матриц
double common_matrix_calculate(
    common_matrix *matrix1,
    common_matrix *matrix2,
    common_matrix *result
    )
{
    START_TIMER

    // Выделение памяти
    common_memory_allocation(matrix1->m, matrix1->n, &(result->M));

    // Присваивание размеров
    result->m = matrix1->m;
    result->n = matrix1->n;

    // Сложение
    for (int i = 0; i < matrix1->m; i++)
        for (int j = 0; j < matrix1->n; j++)
            result->M[i][j] = matrix1->M[i][j] + matrix2->M[i][j];

    END_TIMER
}

// Разреженное сложение матриц
double sparse_matrix_calculate(
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2,
    sparse_matrix *sresult
    )
{
    START_TIMER

    // Сложение
    int i1 = 0;
    int i2 = 0;
    int j1 = 0;
    int j2 = 0;
    node_t *nnum1 = smatrix1->jA->begin;
    node_t *nnum2 = smatrix2->jA->begin;
    
    for (int k = 0; k < smatrix1->A->length + smatrix2->A->length; k++)
    {
        while (nnum1->next != NULL && i1 == nnum1->next->num)
        {
            nnum1 = nnum1->next;
            j1++;
        }
        while (nnum2->next != NULL && i2 == nnum2->next->num)
        {
            nnum2 = nnum2->next;
            j2++;
        }
        int jm = (j1 < j2) ? j1 : j2;
        if (jm >= sresult->jA->length)
            list_push(sresult->jA, sresult->A->length);
        if (j1 == j2)
        {
            if ((smatrix1->iA->nums[i1] == smatrix2->iA->nums[i2]) && i1 < smatrix1->iA->length && i2 < smatrix2->iA->length)
            {
                if (smatrix1->A->nums[i1] + smatrix2->A->nums[i2])
                {
                    vector_push_back(sresult->A, smatrix1->A->nums[i1] + smatrix2->A->nums[i2]);
                    vector_push_back(sresult->iA, smatrix1->iA->nums[i1]);
                }
                i1++;
                i2++;
            }
            else if (smatrix1->iA->nums[i1] > smatrix2->iA->nums[i2] && i2 < smatrix2->iA->length)
            {
                vector_push_back(sresult->A, smatrix2->A->nums[i2]);
                vector_push_back(sresult->iA, smatrix2->iA->nums[i2]);
                i2++;
            }
            else if (smatrix1->iA->nums[i1] < smatrix2->iA->nums[i2] && i1 < smatrix1->iA->length)
            {
                vector_push_back(sresult->A, smatrix1->A->nums[i1]);
                vector_push_back(sresult->iA, smatrix1->iA->nums[i1]);
                i1++;
            }
        }
        else if (j1 < j2 && i1 < smatrix1->iA->length)
        {
            vector_push_back(sresult->A, smatrix1->A->nums[i1]);
            vector_push_back(sresult->iA, smatrix1->iA->nums[i1]);
            i1++;
        }
        else if (j1 > j2 && i2 < smatrix2->iA->length)
        {
            vector_push_back(sresult->A, smatrix2->A->nums[i2]);
            vector_push_back(sresult->iA, smatrix2->iA->nums[i2]);
            i2++;
        }
        // sparse_matrix_output(sresult);
    }

    END_TIMER
}


// Главная функция суммы матриц
error_code matrix_menu_calculate(
    common_matrix *matrix1,
    common_matrix *matrix2,
    sparse_matrix *smatrix1,
    sparse_matrix *smatrix2
    )
{
    // Код ошибки
    error_code error = OK;

    // Результирующая матрица
    common_matrix result = { NULL, 0, 0 };
    sparse_matrix sresult = { NULL, NULL, NULL };
    sparse_memory_allocation(&sresult);

    // Выбор формата сложения
    int choise;
    print_matrix_menu_calculate_interface();
    scanf("%d", &choise);

    // Проверка на размеры
    if (matrix1->m != matrix2->m || matrix1->n != matrix2->n)
        error = SIZE_ERROR;

    // Сложение
    if (!error)
    {
        if (choise == 1)
        {
            double time = common_matrix_calculate(matrix1, matrix2, &result);
            printf("Время сортировки ~ %.6lf (c)\n", time);
            common_in_sparse(&result, &sresult);
        }
        else if (choise == 2)
        {
            result.m = matrix1->m;
            result.n = matrix1->n;
            double time = sparse_matrix_calculate(smatrix1, smatrix2, &sresult);
            printf("Время сортировки ~ %.6lf (c)\n", time);
            // sparse_matrix_output(&sresult);
            sparse_in_common(&sresult, &result);
        }
        else
            printf("Неизвестная команда!\n");
    }

    // Вывод результата
    if (!error)
    {
        print_matrix_calculate_interface();
        scanf("%d", &choise);

        if (choise == 1)
            common_matrix_output(&result);
        else if (choise == 2)
            sparse_matrix_output(&sresult);
        else if (choise != 0)
            printf("Неизвестная команда!\n");
    }

    // Отчистка памяти
    sparse_memory_deallocation(&sresult);
    common_memory_deallocation(result.m, &result.M);

    return error;
}