#include "../inc/errors.h"


// Вывод ошибки на экран
void print_error(error_code e)
{
    switch (e)
    {
        case OK:
            printf("Программа успешно завершена, память отчищена. \nДо свидания :3\n");
            break;
        case WRONG_CAPACITY:
            printf("Неверное количество зарезервированных ячеек памяти!\n");
            break;
        case WRONG_ELEMENT:
            printf("Некорректный ввод элемента\n");
            break;
        case STACK_OWERFLOW:
            printf("Переполнение стэка!\n");
            break;
        case STACK_UNDERFLOW:
            printf("Обращение к пустому стэку\n");
            break;
    }
}