#include <stdio.h>

#include "errors.h"
#include "number.h"
#include "divising.h"

int main()
{
  // Ввод
  char fstring[40];
  char istring[32];
  start_menu(fstring, istring);

  long_real_number mantissa;
  long_int_number divider;
  
  if (convert_long_float_number(&mantissa, fstring))
  {
    printf("Некорректный ввод действительного числа!\n");
    return WRONG_INPUT;
  }

  if (convert_long_int_number(&divider, istring))
  {
    printf("Некорректный ввод целого числа!\n");
    return WRONG_INPUT;
  }
  

  if (zero_check(divider.number, divider.length))
  {
    printf("Ошибка! Деление на ноль!\n");
    return DIVISION_BY_ZERO;
  }
  
  // printf("%d ", mantissa.sign);

  // Деление
  // print_long_number(mantissa);
  // print_long_int(divider);

  main_division(&mantissa, divider.number, &divider.length, divider.sign);

  // print_long_number(mantissa);
  
  print_answer(fstring, istring, mantissa);

  return OK;
}