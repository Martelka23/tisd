#pragma once

#include "number.h"

void multiply(int array[], int *n, int x);

int array_cmp(int *array1, int length1, int *array2, int length2);

int zero_check(int *array, int length);

void subtraction(int num1[], int *n1, int num2[], int n2);

int find_multiplier(int dividend[], int dividend_length, int divider[], int divider_length);

/*
Вспомогательная функция для деления
Записывает в dividend остаток от деления и в multiplier множитель
*/
void mini_div(int dividend[], int *dividend_length, int divider[], int *divider_length, int *multiplier);

void main_division(long_real_number *num, int divisor[], int *n2, char divider_sign);