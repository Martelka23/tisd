#pragma once
#pragma pack(1)


// Коды ошибок
typedef enum errors
{
    OK,
    WRONG_CAPACITY,
    WRONG_ELEMENT,
    ARRAY_OWERFLOW,
    ARRAY_UNDERFLOW,
    STACK_OWERFLOW,
    STACK_UNDERFLOW
} error_code;


// Вывод ошибки на экран
void print_error(error_code e);