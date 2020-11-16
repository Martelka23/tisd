#include "../inc/work_with_list_stack.h"


// Главное меню работы со стэком на списке
error_code menu_list_stack()
{
    error_code error = OK;
    list_stack_t list_stack;
    list_stack_init(&list_stack);
    int choise;
    address_monitoring_t address_monitoring;
    address_monitoring_init(&address_monitoring);

    do
    {
        interface_work_with_list_stack();
        scanf("%d", &choise);

        switch (choise)
        {
            case MANUAL_FILLING:
                error = list_stack_manual_filling(&list_stack, &address_monitoring);
                break;
            case AUTO_FILLING:
                error = list_stack_auto_filling(&list_stack, &address_monitoring);
                break;
            case OUTPUT_ELEMS:
                list_stack_output_elems(&list_stack, &address_monitoring);
                break;
            case DESCRIPTION:
                list_stack_description(&list_stack, &address_monitoring);
                break;
            case EXIT_TO_MAIN_MENU:
                list_stack_del(&list_stack);
                address_monitoring_del(&address_monitoring);
                break;
            
            default:
                printf("Неверная команда, будьте внимательнее!\n");
                break;
        }
    } while (!error && choise);

    return error;
}

// Ввод элементов вручную
error_code list_stack_manual_filling(list_stack_t *list_stack, address_monitoring_t *address_monitoring)
{
    int count;
    error_code error = OK;

    printf("Заполненность стэка: %d\n", list_stack->length);

    printf("Сколько элементов хотите добавить в стэк на массиве: ");
    error = (scanf("%d", &count) != 1 || count < 0) ? WRONG_COUNT : OK;

    printf("Введите элементы: ");
    for (int i = 0; i < count && !error; i++)
    {
        int x;
        if (scanf("%d", &x) == 1)
        {
            list_stack_add(list_stack, x);
            addresses_array_push_back(&address_monitoring->allocated, &list_stack->end->num);
        }
        else
            error = WRONG_ELEMENT;
    }

    return error;
}

// Ввод элементов автоматически
error_code list_stack_auto_filling(list_stack_t *list_stack, address_monitoring_t *address_monitoring)
{
    int begin, end;
    error_code error = OK;

    printf("Заполненность стэка: %d\n", list_stack->length);

    printf("Введите начало (наибольшее число) и конец диапазона (наименьшее число): ");
    error = (scanf("%d %d", &begin, &end) != 2 || begin < end) ? WRONG_RANGE : OK;

    for (int i = begin; i >= end && !error; i--)
    {
        list_stack_add(list_stack, i);
        addresses_array_push_back(&address_monitoring->allocated, &list_stack->end->num);
    }

    return error;
}

// Вывод элементов стэка
error_code list_stack_output_elems(list_stack_t *list_stack, address_monitoring_t *address_monitoring)
{
    
    int count;
    error_code error = OK;

    printf("Заполненность стэка: %d\n", list_stack->length);

    printf("Сколько элементов из стэка хотите вывести (введите 0, чтобы вывести все элементы): ");
    error = (scanf("%d", &count) != 1 || count < 0) ? WRONG_COUNT : OK;
    count = (count == 0) ? list_stack->length : count;

    for (int i = 0; i < count && !error; i++)
    {
        int x;
        int *address;

        addresses_array_pop(&address_monitoring->allocated, &address);
        addresses_array_push_back(&address_monitoring->deallocated, address);

        error = list_stack_pop(list_stack, &x);
        if (!error)
            printf("%d ", x);
    }

    return error;
}

// Описание стэка на списке
void list_stack_description(list_stack_t *list_stack, address_monitoring_t *address_monitoring)
{
    printf(
        "\n*****Описание стэка*****\n"
        "Название: стэк на списке.\n"
        "Указатель на начало: %p.\n"
        "Указатель на вершину: %p.\n",
        (void *)list_stack->begin, (void *)list_stack->end
    );
    printf("Заполненность стэка: %d\n", list_stack->length);
    address_monitoring_print(address_monitoring);
}