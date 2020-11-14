#pragma once

#include <stdio.h>

typedef enum error_code
{
    OK,
    INPUT_ERROR,
    SIZE_ERROR,
    MEMORY_ALLOCATION_ERROR,
    OPEN_ERROR,
    WRONG_ELEMENTS_COUNT,
    INDEX_ERROR
} error_code;

void print_error(int e);