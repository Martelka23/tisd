#pragma once
#pragma pack (1)

#include <stdlib.h>

#include "errors.h"


// Узел списка
typedef struct node
{
    int num;
    struct node *prev;
} node_t;

// Структура стэка на списке
typedef struct list_stack
{
    node_t *begin;
    node_t *end;
    int length;
} list_stack_t;