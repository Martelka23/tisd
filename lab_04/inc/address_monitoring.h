#pragma once

#include <stdio.h>
#include <stdlib.h>


// Структура массива адресов
typedef struct addresses_array
{
    int **addresses;
    int length;
    int capacity;
} addresses_array_t;

// Структура мониторинга адресов
typedef struct address_monitoring
{
    addresses_array_t allocated;
    addresses_array_t deallocated;
} address_monitoring_t;


// Выделение памяти под массив адресов
void addresses_array_memory_allocation(addresses_array_t *addresses_array);
// Конструктор массива адресов
void addresses_array_init(addresses_array_t *addresses_array);
// Конструктор мониторинга адресов
void address_monitoring_init(address_monitoring_t *address_monitoring);
// Освобождение памяти массива адресов
void addresses_array_memory_deallocation(addresses_array_t *addresses_array);
// Деструктор массива адресов
void addresses_array_del(addresses_array_t *addresses_array);
// Деструктор мониторинга адресов
void address_monitoring_del(address_monitoring_t *address_monitoring);
// Добавление элемента в массив адресов
void addresses_array_push_back(addresses_array_t *addresses_array, int *x);
// Удаление элемента из массива адресов
void addresses_array_pop(addresses_array_t *addresses_array, int **x);
// Вывести на экран массив адресов
void addresses_array_print(addresses_array_t *addresses_array);
// Вывести на экран мониторинг адресов
void address_monitoring_print(address_monitoring_t *address_monitoring);