#pragma once

#include <time.h>

#include "errors.h"
#include "subscribers.h"
#include "interface.h"

#define START_TIMER clock_t t; \
    t = clock();
#define END_TIMER t = clock() - t; \
    return ((double)t)/CLOCKS_PER_SEC;

typedef struct
{
    char surname[MAX_NAME_LENGTH];
    int index;
} key_sort;

// Перестановка записей
void swap(subscriber *a, subscriber *b);
// Перестановка ключей
void swap_keys(int *a, int *b);
// Вывод ключей на экран
void print_keys(int *a, int l);
// Сравнение записей
int subcmp(subscriber *a, subscriber *b);
// Сортировка пузырьком без ключей
double bubble_sort_no_keys(subscribers *subs);
// Сортировка пузырьком с ключами
double bubble_sort_with_keys(subscribers *subs, int print);
// Быстрая сортировка без ключей
double quick_sort_no_keys(subscriber *subs, int first, int last);
// Быстрая сортировка с ключпми
void qsort_with_keys(subscriber *subs, int *keys, int first, int last);
// Запуск быстрой сортировки с ключами
double quick_sort_with_keys(subscribers *subs, int print);
// Главная функция сортировки
double main_sort(subscribers *subs, int choise, int print);
// Меню сортировки
error_code sort_subs(subscribers *subs);