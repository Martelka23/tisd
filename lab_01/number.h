#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "errors.h"

#define MANTISSA_MAX_LENGTH 30
#define ORDER_MAX_LENGTH 6

typedef struct
{
  char sign;
  int point_position;
  int exp_position;
  int mantissa[MANTISSA_MAX_LENGTH + 1];
  int mantissa_length;
  char order_sign;
  int order;
} long_real_number;

typedef struct
{
  char sign;
  int number[MANTISSA_MAX_LENGTH];
  int length;
} long_int_number;

int print_answer(char *fstring, char *istring, long_real_number num);

void print_long_number(long_real_number num);

void print_long_int(long_int_number num);

void array_copy(int source_array[], int source_length, int target_array[]);


void shift_right(int array[], int n);

void shift_left(int array[], int n);


void round_mantissa(long_real_number *num, int new_len);

int count_lead_nils(int number_array[], int n);

void eliminate_lead_nils(int array[], int *n);

void eliminate_last_nils(long_real_number *num);

void eliminate_last_nils_for_num(long_int_number *num);

void start_menu(char *fstring, char *istring);

int parse_sign(char *string, long_real_number *num);


int parse_point(char *string, long_real_number *num);


int parse_exp_sign(char *string, long_real_number *num);

int parse_mantissa_part(char *string, long_real_number *num);


int parse_order_part(char *string, long_real_number *num);

error_code convert_long_int_number(long_int_number *num, char *istring);

error_code convert_long_float_number(long_real_number *num, char *fstring);