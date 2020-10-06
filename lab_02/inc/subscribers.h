#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "errors.h"

#define SYMBOL_LENGTH 1
#define MAX_NAME_LENGTH 61
#define MAX_ADDRESS_LENGTH 131
#define MAX_SUBS_LENGTH 51
#define MAX_INPUT_LENGTH 51

// Структура даты
typedef struct
{
    unsigned short int year;  // 2 байта
    unsigned short int month;  // 2 байта
    unsigned short int day;  // 2 байта
} date;

// Структура личного статуса
typedef struct
{
    date birthday;  // 6 байт
} private_status;

// Структура служебного статуса
typedef struct
{
    char position[MAX_NAME_LENGTH];  // 31 байт
    char organization[MAX_NAME_LENGTH];  // 31 байт
} service_status;

// Объединение статусов
typedef union
{
    private_status private_;  // 6 байт
    service_status service;  // 62 байт
} number_status;

// Структура абонента
typedef struct
{
    char surname[MAX_NAME_LENGTH];  // 31 байт
    char name[MAX_NAME_LENGTH];  // 31 байт
    unsigned long int number;  // 8 байт
    char address[MAX_ADDRESS_LENGTH];  // 51 байт
    char status_type;  // 1 байт
    number_status status; // 66 байт
} subscriber;  // 191 байт

// Структура массива
typedef struct
{
    subscriber sub[MAX_SUBS_LENGTH];  // 191 байт
    unsigned short int length; // 2 байта
    unsigned short int capacity; // 2 байта
} subscribers;


// error_code memory_allocation(subscribers *subs);

size_t read_count_of_elements(FILE *file);

void read_elements(FILE *file, subscribers *subs);

error_code read_subs(subscribers *subs);
// Функция вывода на экран
void print_all_subscribers(subscribers *subs);
// Функция добавления абонента
error_code add_sub(subscribers *subs);
void rm(subscribers *subs, int index);
void del_sub(subscribers *subs);
void read_string(char *s);