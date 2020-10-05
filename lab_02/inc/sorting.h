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

void sub_cpy(subscribers *subs, subscribers *new);

void swap(subscriber *a, subscriber *b);

void swap_keys(int *a, int *b);

int subcmp(subscriber *a, subscriber *b);

double bubble_sort_no_keys(subscribers *subs);

double bubble_sort_with_keys(subscribers *subs);

double quick_sort_no_keys(subscriber *subs, int first, int last);

void qsort_with_keys(subscriber *subs, int *keys, int first, int last);
double quicksort_with_keys(subscribers *subs);

error_code sort_subs(subscribers *subs);

double main_sort(subscribers *sorted, int choise, int print);