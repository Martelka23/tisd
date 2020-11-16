#pragma once

#include <stdio.h>

// Варианты главного меню
typedef enum main_menu_choise
{
    EXIT,
    GET_INFO,
    ARRAY_STACK,
    LIST_STACK
} main_menu_choise;

// Варианты работы со стэком на массиве
typedef enum menu_stack_choise
{
    EXIT_TO_MAIN_MENU,
    MANUAL_FILLING,
    AUTO_FILLING,
    OUTPUT_ELEMS,
    DESCRIPTION
} menu_stack_choise;

// Варианты работы со стэком на списке
// typedef enum menu_list_stack_choise
// {
//     EXIT,
//     MANUAL_FILLING,
//     AUTO_FILLING,
//     OUTPUT_ELEMS,
//     DESCRIPTION
// } menu_list_stack_choise;


// Интерфейс главного меню
void interface_main_menu();
// Инструкция к программе
void interface_read_me();
// Интерфейс работы со стэком
void interface_work_with_stack();
// Интерфейс работы со стэком на массиве
void interface_work_with_array_stack();
// Интерфейс работы со стэком на связанном списке
void interface_work_with_list_stack();