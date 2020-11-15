#include "../inc/work_with_array_stack.h"


// Главное меню работы со стэком на массиве
error_code menu_array_stack()
{
    error_code error = OK;
    array_stack_t array_stack;
    array_stack_init(&array_stack);
    menu_array_stack_choise choise;
    address_monitoring_t address_monitoring;
    address_monitoring_init(&address_monitoring);
    array_stack_addresses_copy(&array_stack, &address_monitoring);

    do
    {
        interface_work_with_array_stack();
        scanf("%d", &choise);

        switch (choise)
        {
            case MANUAL_FILLING:
                error = array_stack_manual_filling(&array_stack);
                break;
            case AUTO_FILLING:
                error = array_stack_auto_filling(&array_stack);
                break;
            case OUTPUT_ELEMS:
                array_stack_output_elems(&array_stack);
                break;
            case DESCRIPTION:
                array_stack_description(&array_stack, &address_monitoring);
                break;
            case EXIT:
                break;
            
            default:
                printf("Неверная команда, будьте внимательнее!\n");
                break;
        }
    } while (!error && choise);

    return error;
}


// Копирование адресов из стэка на массиве в мониторинг адресов
void array_stack_addresses_copy(array_stack_t *array_stack, address_monitoring_t *address_monitoring)
{
    for (int i = 0; i < array_stack->capacity; i++)
        addresses_array_push_back(address_monitoring->allocated, &array_stack->begin[i]);
}

// Ввод элементов вручную
error_code array_stack_manual_filling(array_stack_t *array_stack)
{
    int count;
    error_code error = OK;

    printf("Заполненность стэка: %d / %d", array_stack->end - array_stack->begin, array_stack->capacity);

    printf("Сколько элементов хотите добавить в стэк на массиве: ");
    error = (scanf("%d", &count) != 1 || count < 0) ? WRONG_COUNT : OK;

    printf("Введите элементы: ");
    for (int i = 0; i < count && !error; i++)
    {
        int x;
        if (scanf("%d", &x) == 1)
            error = array_stack_add(array_stack, x);
        else
            error = WRONG_ELEMENT;
    }

    return error;
}

// Ввод элементов автоматически
error_code array_stack_auto_filling(array_stack_t *array_stack)
{
    int begin, end;
    error_code error = OK;

    printf("Заполненность стэка: %d / %d", array_stack->end - array_stack->begin, array_stack->capacity);

    printf("Введите начало (наибольшее число) и конец диапазона (наименьшее число): ");
    error = (scanf("%d %d", &begin, &end) != 2 || begin < end) ? WRONG_RANGE : OK;

    for (int i = begin; i >= end && !error; i--)
        error = array_stack_add(array_stack, i);

    return error;
}

// Вывод элементов стэка
error_code array_stack_output_elems(array_stack_t *array_stack)
{
    int count;
    error_code error = OK;

    printf("Заполненность стэка: %d / %d", array_stack->end - array_stack->begin, array_stack->capacity);

    printf("Сколько элементов из стэка хотите вывести (введите 0, чтобы вывести все элементы): ");
    error = (scanf("%d", &count) != 1 || count < 0) ? WRONG_COUNT : OK;
    count = (count == 0) ? array_stack->end - array_stack->begin : count;

    for (int i = 0; i < count && !error; i++)
    {
        int x;
        error = array_stack_pop(array_stack, &x);
        if (!error)
            printf("%3d ", x);
    }

    return error;
}

// Описание стэка на массиве
void array_stack_description(array_stack_t *array_stack, address_monitoring_t *address_monitoring)
{
    printf(
        "\n*****Описание стэка*****\n"
        "Название: стэк на массиве.\n"
        "Указатель на начало: %d.\n"
        "Указатель на вершину: %d.\n",
        array_stack->begin, array_stack->end
    );
    printf("Заполненность стэка: %d / %d", array_stack->end - array_stack->begin, array_stack->capacity);
    address_monitoring_print(address_monitoring);
}