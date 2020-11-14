#include "../inc/errors.h"

void print_error(int e)
{
    switch (e)
    {
    case OK:
        printf("До свидания!)\n");
        break;
    case INPUT_ERROR:
        printf("Ошибка ввода!\n");
        break;
    case SIZE_ERROR:
        printf("Неправильный размер!\n");
        break;
    case MEMORY_ALLOCATION_ERROR:
        printf("Ошибка выделения памяти!\n");
        break;
    case OPEN_ERROR:
        printf("Невозможно открыть файл!\n");
        break;
    case WRONG_ELEMENTS_COUNT:
        printf("Количество ненулевых элементов больше допустимого!\n");
        break;
    case INDEX_ERROR:
        printf("Недопустимый индекс!\n");
        break;
    }
}