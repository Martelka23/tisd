#include "divising.h"

void multiply(int array[], int *n, int x)
{
  int temp = 0;

  for (int i = *n - 1; i > 0; i--)
  {
    array[i] = array[i] * x + temp;
    temp = 0;

    if (array[i] >= 10)
    {
      temp = array[i] / 10;
      array[i] %= 10;
    }
  }

  array[0] = array[0] * x + temp;

  if (array[0] >= 10)
  {
    (*n)++;
    shift_right(array, *n);
    array[0] = array[1] / 10;
    array[1] %= 10;
  }
}

int array_cmp(int *array1, int length1, int *array2, int length2)
{
  if (length1 != length2)
  {
    if (length1 > length2)
      return 1;
    return -1;
  }
  else
  {
    for (int i = 0; i < length1; i++)
    {
      if (array1[i] != array2[i])
      {
        if (array1[i] > array2[i])
          return 1;

        return -1;
      } 
    }
  }

    return 0;
}

int zero_check(int *array, int length)
{
  int zero[1] = {0};
  return array_cmp(array, length, zero, 1) == 0;
}

void subtraction(int num1[], int *n1, int num2[], int n2)
{
  int i = *n1 - 1, j = n2 - 1;
  int checker = 0;

  while (i >= 0 && j >= 0)
  {
    if (num1[i] - num2[j] < 0)
    {
      num1[i] = 10 + num1[i] - num2[j];
      num1[i - 1] -= 1;
      checker = 1;
    }
    else
    {
      checker = 0;
      num1[i] -= num2[j];
    }
    i--;
    j--;
  }

  if (i > 0 && checker == 1)
  {
    while (num1[i] == -1)
    {
      if (num1[i] == -1)
      {
        num1[i] = 9;
        num1[i - 1] -= 1;
        i--;
      }
    }
  }

  if (num1[0] == 0)
  {
    eliminate_lead_nils(num1, n1);
  }

  if (*n1 <= 0)
  {
    *n1 = 1;
  }
}

int find_multiplier(int dividend[], int dividend_length, int divider[], int divider_length)
{
  // Множитель
  int multiplier = 1;
  // Поиск множителя
  for (; multiplier <= 9; multiplier++)
  {
    // Результат умножения делителя на множитель
    int result_of_multiply[100];
    array_copy(divider, divider_length, result_of_multiply);
    int result_length = divider_length;
    // Умножение делителя на множитель
    multiply(result_of_multiply, &result_length, multiplier);
    // Проверка на подходящий множитель
    int cmp_res = array_cmp(result_of_multiply, result_length, dividend, dividend_length);

    if (cmp_res == 1)
    {
      return multiplier - 1;
    }
  }

  // Случай, когда множитель равен 9
  return multiplier - 1;
}

void mini_div(int dividend[], int *dividend_length, int divider[], int *divider_length, int *multiplier)
{
  // Поиск множителя
  int multiplier_tmp = find_multiplier(dividend, *dividend_length, divider, *divider_length);
  *multiplier = multiplier_tmp;
  // Умножение делителя на множитель
  int result_of_multiply[60];
  array_copy(divider, *divider_length, result_of_multiply);
  int result_length = *divider_length;
  multiply(result_of_multiply, &result_length, *multiplier);
  // Вычитание из делимого результата умножения
  subtraction(dividend, dividend_length, result_of_multiply, result_length);
}


void main_division(long_real_number *num, int divisor[], int *n2, char divider_sign)
{
  if (!zero_check(num->mantissa, num->mantissa_length))
  {
    num->sign = (num->sign == divider_sign) ? '+' : '-';

    int result_division[100];
    int n_res_div = 0;
    int temp_dividend[100] = {0};
    int n_temp = 0;

    int i = 0;

    while ((i < num->mantissa_length || n_temp > 0) && i < 60)
    {
      if (i < num->mantissa_length)
      {
        temp_dividend[n_temp] = num->mantissa[i];
        n_temp++;
      }

      if (i >= num->mantissa_length)
      {
        temp_dividend[n_temp] = 0;
        n_temp++;
      }

      int cmp_res = array_cmp(temp_dividend, n_temp, divisor, *n2);

      if (cmp_res == 1 || cmp_res == 0)
      {
        eliminate_lead_nils(temp_dividend, &n_temp);
        int result;
        
        mini_div(temp_dividend, &n_temp, divisor, n2, &result);

        result_division[n_res_div] = result;
        n_res_div++;
      }

      if (cmp_res == -1)
      {
        result_division[n_res_div] = 0;
        n_res_div++;
      }        
      i++;
      eliminate_lead_nils(temp_dividend, &n_temp);
    }

    num->order -= count_lead_nils(result_division, n_res_div);
    eliminate_lead_nils(result_division, &n_res_div);
    num->mantissa_length = (n_res_div > 31) ? 31 : n_res_div;
    int new_result_len = num->mantissa_length;
    array_copy(result_division, new_result_len, num->mantissa);
    round_mantissa(num, 30);
    eliminate_last_nils(num);
  }
}