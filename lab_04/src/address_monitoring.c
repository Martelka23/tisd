#include "../inc/address_monitoring.h"


// Выделение памяти под массив адресов
void addresses_array_memory_allocation(addresses_array_t *addresses_array)
{
    addresses_array->addresses = calloc((size_t)addresses_array->capacity, sizeof(int *));
}

// Конструктор массива адресов
void addresses_array_init(addresses_array_t *addresses_array)
{
    addresses_array->addresses = NULL;
    addresses_array->length = 0;
    addresses_array->capacity = 20;
    addresses_array_memory_allocation(addresses_array);
}

// Конструктор мониторинга адресов
void address_monitoring_init(address_monitoring_t *address_monitoring)
{
    addresses_array_init(&address_monitoring->allocated);
    addresses_array_init(&address_monitoring->deallocated);
}

// Освобождение памяти массива адресов
void addresses_array_memory_deallocation(addresses_array_t *addresses_array)
{
    free(addresses_array->addresses);
}

// Деструктор массива адресов
void addresses_array_del(addresses_array_t *addresses_array)
{
    addresses_array_memory_deallocation(addresses_array);
    addresses_array->addresses = NULL;
    addresses_array->length = 0;
    addresses_array->capacity = 0;
}

// Деструктор мониторинга адресов
void address_monitoring_del(address_monitoring_t *address_monitoring)
{
    addresses_array_del(&address_monitoring->allocated);
    addresses_array_del(&address_monitoring->deallocated);
}

// Добавление элемента в массив адресов
void addresses_array_push_back(addresses_array_t *addresses_array, int *x)
{
    if (x != NULL)
        addresses_array->addresses[addresses_array->length++] = x;
}

// Удаление элемента из массива адресов
void addresses_array_pop(addresses_array_t *addresses_array, int **x)
{
    *x = addresses_array->addresses[addresses_array->length - 1];
    addresses_array->length--;
}

// Вывести на экран массив адресов
void addresses_array_print(addresses_array_t *addresses_array)
{
    for (int i = 0; i < addresses_array->length; i++)
        printf("%p\n", (void *)addresses_array->addresses[i]);
}

// Вывести на экран мониторинг адресов
void address_monitoring_print(address_monitoring_t *address_monitoring)
{
    printf("Занятая память:\n");
    addresses_array_print(&address_monitoring->allocated);
    printf("Освобожденная память:\n");
    addresses_array_print(&address_monitoring->deallocated);
}