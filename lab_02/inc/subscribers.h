#pragma once
#pragma pack(1)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "errors.h"

#define SYMBOL_LENGTH 1
#define MAX_NAME_LENGTH 31 * 3
#define MAX_ADDRESS_LENGTH 51 * 3
#define MAX_SUBS_LENGTH 51
#define MAX_INPUT_LENGTH 51 * 3

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
    char position[MAX_NAME_LENGTH];  // 93 байт
    char organization[MAX_NAME_LENGTH];  // 93 байт
} service_status;

// Объединение статусов
typedef union
{
    private_status private_;  // 6 байт
    service_status service;  // 186 байт
} number_status;

// Структура абонента
typedef struct
{
    char surname[MAX_NAME_LENGTH];  // 31 байт
    char name[MAX_NAME_LENGTH];  // 31 байт
    unsigned long int number;  // 8 байт
    char address[MAX_ADDRESS_LENGTH];  // 51 байт
    char status_type;  // 1 байт
    number_status status; // 186 байт
} subscriber;  // 308 байт

// Структура массива
typedef struct
{
    subscriber sub[MAX_SUBS_LENGTH];  // 314 байт
    unsigned short int length; // 2 байта
} subscribers; // 310


// Глубокое копирование записи
void sub_cpy(subscribers *subs, subscribers *new);
// Подсчёт полей из файла
size_t read_count_of_elements(FILE *file);
// Форматирование строки при вводе
void formating(char *string, int max_length);
// Считывание записей из файла
void read_elements(FILE *file, subscribers *subs);
// Считывание записей
error_code read_subs(subscribers *subs);
// Функция вывода на экран
void print_all_subscribers(subscribers *subs);
// Считывание строки
void read_string(char *s);
// Функция добавления абонента
error_code add_sub(subscribers *subs);
// Удаление записи
void rm(subscribers *subs, int index);
// Выбор и удаление записей
error_code del_sub(subscribers *subs);
// Показать пользователей с днём рождения на этой неделе
void show_birthsday(subscribers *subs);