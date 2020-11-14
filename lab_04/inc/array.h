#pragma once
#pragma pack(1)


#include <stdio.h>
#include <stdlib.h>

#include "errors.h"


// Структура массива
typedef struct array
{
    int *nums;
    int length;
    int capacity;
} array_t;


