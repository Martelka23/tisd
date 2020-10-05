#include <stdio.h>

#include "divising.h"

void print_array(int array[], int len)
{
  for (int i = 0; i < len; i++)
   printf("%d ", array[i]);
  printf("\n");
}

int main()
{
  // printf("Test array_cmp:\n");
  // // 00101
  // {
  //   int a1[10] = {1, 2, 3};
  //   int a2[20] = {1, 2, 3};

  //   printf("%d", array_cmp(a1, 3, a2, 3));
  // }
  // {
  //   int a1[10] = {1, 3};
  //   int a2[20] = {1, 2, 3};

  //   printf("%d", array_cmp(a1, 1, a2, 3));
  // }
  // {
  //   int a1[10] = {1, 2, 3};
  //   int a2[20] = {2, 3};

  //   printf("%d", array_cmp(a1, 3, a2, 2));
  // }
  // {
  //   int a1[10] = {1, 2, 3};
  //   int a2[20] = {3, 2, 3};

  //   printf("%d", array_cmp(a1, 3, a2, 3));
  // }
  // {
  //   int a1[10] = {1, 3, 3};
  //   int a2[20] = {1, 2, 3};

  //   printf("%d", array_cmp(a1, 3, a2, 3));
  // }
  // printf("\n\n");

  // printf("Test substraction:\n");
  // // dividend = 6
  // // multiplier = 117
  // {
  //   int first[10] = {1,2,3};
  //   int first_length = 3;
  //   int second[10] = {1,1,7};
  //   int second_length = 3;
  //   subtraction(first, &first_length, second, second_length);
  //   printf("first = ");
  //   print_array(first, first_length);
  //   printf("second = ");
  //   print_array(second, second_length);
  // }
  // printf("\n");

  // printf("Test mini_div:\n");
  // // dividend = 6
  // // multiplier = 9
  // {
  //   int dividend[10] = {1,2,3};
  //   int dividend_length = 3;
  //   int divider[10] = {1,3};
  //   int divider_length = 2;
  //   int multiplier;
  //   mini_div(dividend, &dividend_length, divider, &divider_length, &multiplier);
  //   printf("dividend = ");
  //   print_array(dividend, dividend_length);
  //   printf("multiplier = %d\n", multiplier);
  // }
  // // dividend = 1
  // // multiplier = 8
  // {
  //   int dividend[10] = {1,0,5};
  //   int dividend_length = 3;
  //   int divider[10] = {1,3};
  //   int divider_length = 2;
  //   int multiplier;
  //   mini_div(dividend, &dividend_length, divider, &divider_length, &multiplier);
  //   printf("dividend = ");
  //   print_array(dividend, dividend_length);
  //   printf("multiplier = %d\n", multiplier);
  // }
  // // dividend = 0
  // // multiplier = 8
  // {
  //   int dividend[10] = {1,0,4};
  //   int dividend_length = 3;
  //   int divider[10] = {1,3};
  //   int divider_length = 2;
  //   int multiplier;
  //   mini_div(dividend, &dividend_length, divider, &divider_length, &multiplier);
  //   printf("dividend = ");
  //   print_array(dividend, dividend_length);
  //   printf("multiplier = %d\n", multiplier);
  // }
  // // dividend = 0
  // // multiplier = 1
  // {
  //   int dividend[10] = {1,0,0,0};
  //   int dividend_length = 4;
  //   int divider[10] = {1,0,0,0};
  //   int divider_length = 4;
  //   int multiplier;
  //   mini_div(dividend, &dividend_length, divider, &divider_length, &multiplier);
  //   printf("dividend = ");
  //   print_array(dividend, dividend_length);
  //   printf("multiplier = %d\n", multiplier);
  // }
  // // dividend = 1
  // // multiplier = 9
  // {
  //   int dividend[10] = {1,0,0};
  //   int dividend_length = 3;
  //   int divider[10] = {1,1};
  //   int divider_length = 2;
  //   int multiplier;
  //   mini_div(dividend, &dividend_length, divider, &divider_length, &multiplier);
  //   printf("dividend = ");
  //   print_array(dividend, dividend_length);
  //   printf("multiplier = %d\n", multiplier);
  // }
  // // dividend = 0
  // // multiplier = 1
  // {
  //   int dividend[10] = {1};
  //   int dividend_length = 1;
  //   int divider[10] = {1};
  //   int divider_length = 1;
  //   int multiplier;
  //   mini_div(dividend, &dividend_length, divider, &divider_length, &multiplier);
  //   printf("dividend = ");
  //   print_array(dividend, dividend_length);
  //   printf("multiplier = %d\n", multiplier);
  // }



  int dividend[10] = {5};
  int n1 = 1;
  int divisor[10] = {8, 0};
  int n2 = 2;

  int result[10];
  int n = 0;


  main_division(dividend, n1, divisor, &n2, result, &n);
  printf("len of result = %d\n", n);
  printf("result array = \n");
  printf("count of nils = %d \n", count_lead_nils(result, n));
  print_array(result, n);
  
  // { 
  //   int a[] = {1,6,9,5};
  //   int n = 4;
  //   printf("before rounding ");
  //   print_array(a, n);
  //   round_array(a, &n, 3);
  //   printf("result is ");
  //   print_array(a, n);
  //   printf("\n");
  // }
  // { 
  //   int a[] = {9,9,9,9};
  //   int n = 4;
  //   printf("before rounding ");
  //   print_array(a, n);
  //   round_array(a, &n, 3);
  //   printf("result is ");
  //   print_array(a, n);
  //   printf("\n");
  // }

  return 0;
}