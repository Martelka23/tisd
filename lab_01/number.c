#include "number.h"

int print_answer(char *fstring, char *istring, long_real_number num)
{
  if (num.order <= -100000 || num.order >= 100000)
  {
    printf("Переполнение порядка!\n");
    return 1;
  }
  printf("%s / %s = ", fstring, istring);
  if (num.mantissa_length == 0)
  {
    printf("0\n");
  } else
  {
    printf("%c0.", num.sign);
    for (int i = 0; i < num.mantissa_length; i++)
      printf("%d", num.mantissa[i]);
    printf("E%d\n", num.order);
  }
  return 0;
}

void print_long_number(long_real_number num)
{
  printf("sign %c\n", num.sign);
  printf("point position %d\n", num.point_position);
  printf("exp position %d\n", num.exp_position);
  printf("mantissa ");
  for (int i = 0; i < num.mantissa_length; i++)
    printf("%d ", num.mantissa[i]);
  printf("\n");
  printf("mantissa_length %d\n", num.mantissa_length);
  printf("order_sign %c\n", num.order_sign);
  printf("order %d\n\n", num.order);
}

void print_long_int(long_int_number num)
{
  printf("sign %c\n", num.sign);
  printf("number ");
  for (int i = 0; i < num.length; i++)
    printf("%d ", num.number[i]);
  printf("\nlength %d\n\n", num.length);
}

void array_copy(int source_array[], int source_length, int target_array[])
{
  for (int i = 0; i < source_length; i++)
    target_array[i] = source_array[i];
}

void shift_right(int array[], int n)
{
  for (int i = n - 1; i > 0; i--)
  {
    array[i] = array[i - 1];
  }
}

void shift_left(int array[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    array[i] = array[i + 1];
  }
}

void round_mantissa(long_real_number *num, int new_len)
{
  if (num->mantissa_length > new_len)
  {
    if (num->mantissa[new_len] >= 5)
      num->mantissa[new_len - 1]++;
    for (int i = new_len - 1; i > 0; i--)
    {
      if (num->mantissa[i] > 9)
      {
        num->mantissa[i - 1]++;
        num->mantissa[i] %= 10;
      }
    }
    num->mantissa_length = new_len;
    if (num->mantissa[0] > 9)
    {
      (num->mantissa_length)++;
      (num->order)--;
      shift_right(num->mantissa, num->mantissa_length);
      num->mantissa[1] = 0;
      num->mantissa[0] = 1;
    }
  }
}

int count_lead_nils(int number_array[], int n)
{
  int lead_nils = 0;
  for (int i = 0; i < n; i++)
  {
    if (number_array[i] != 0)
      break;
            
    lead_nils++;
  }

  return lead_nils;
}
void eliminate_lead_nils(int array[], int *n)
{
    
  int temp_array[100];
  array_copy(array, *n, temp_array);

  int i = 0;
  while (temp_array[i] == 0)
    i++;

  int count_spaces = i;

  int j = 0;
  while (i < *n)
    array[j++] = temp_array[i++];

    
  *n = *n - count_spaces;

  if (*n < 0)
    *n = 0;
}

void eliminate_last_nils(long_real_number *num)
{
  while (num->mantissa[num->mantissa_length - 1] == 0)
  {
    (num->mantissa_length)--;
  }
}

void eliminate_last_nils_for_num(long_int_number *num)
{
  while (num->number[num->length - 1] == 0)
  {
    (num->length)--;
  }
  if (num->length == 0)
    num->length = 1;
}

void start_menu(char *fstring, char *istring)
{
  printf("%s",
    "Деление числа с плавающей точкой на целое число\n\n"
    "Правила ввода:\n"
    "1. Перед мантиссой укажите её знак. ('+' или '-').\n"
    "2. Перед порядком укажите знак экспоненты. ('E' или 'e').\n"
    "3. Укажите знак порядка. ('+' или '-').\n"
    "4. Ведущие нули допустимы.\n"
    "5. Плавающаю точку нужно записать в виде точки\n"
    "6. Целое число может состоять максимум из 31 символа "
    "(1 символ на знак числа и 30 символов на число).\n"
    "7. Число с плавающей точно может состоять максимум из "
    "39 символов (1 символ на знак числа, 1 символ на точку (опционально), "
    "30 символов на мантиссу, 1 символ на знак экспоненты (опционально), "
    "1 символ на знак порядка, 5 символов на порядок.\n\n");

  printf("%s",
    "                         знак|          мантисса           |E±|pwr|\n"
    "                            -|--------|---------|----------|--|---|\n"
    "                             1       10        20        31\n"
    "Введите вещественное число: ");
  scanf("%s", fstring);

  printf("%s",
    "                         знак|        целое число         |\n"
    "                            -|--------|---------|---------|\n"
    "                             1       10        20        30\n"
    "Введите целое число:        ");
  scanf("%s", istring);
}

int parse_sign(char *string, long_real_number *num)
{
  if (string[0] == '-' || string[0] == '+')
  {
    num->sign = string[0];
    return OK;
  } else
    return WRONG_SIGN;
}

int parse_point(char *string, long_real_number *num)
{
  if (parse_sign(string, num) != OK)
  {
      return WRONG_INPUT;
  }

  short int string_length = (short)strlen(string);

  short int string_index = 0;
  int point_pos = -1;
  short int point_check = 0;

  while (string_index < string_length)
  {
    if (string[string_index] == '.')
    {
      if (!point_check)
      {
        point_pos = string_index;
        point_check = 1;
      }

      else
      {
        return WRONG_POINT;
      }
    }

    string_index++;
  }


  num->point_position = point_pos - 1;

  return OK;
}

int parse_exp_sign(char *string, long_real_number *num)
{
  if (parse_point(string, num) != OK)
  {
    return WRONG_INPUT;
  }

  short int string_length = (short)strlen(string);

  short int string_index = 0;
  short int exp_pos;

  while (string_index < string_length)
  {
    if (string[string_index] == 'E' || string[string_index] == 'e')
    {
      exp_pos = string_index--;
      break;
    } else
      string_index++;
  }

  if (string_index == string_length)
  {
    exp_pos = -1;
  }

  num->exp_position = exp_pos;

  return OK;
}

int parse_mantissa_part(char *string, long_real_number *num)
{
  if (parse_exp_sign(string, num) != OK)
  {
    return WRONG_INPUT;
  }

  short int mantissa_begin = 1;
  short int mantissa_end = (num->exp_position == -1) ? (short)strlen(string) : (short)num->exp_position;

  if ((num->point_position == -2 && mantissa_end - mantissa_begin > MANTISSA_MAX_LENGTH) ||
      (num->point_position != -2 && mantissa_end - mantissa_begin > MANTISSA_MAX_LENGTH + 1))
  {
    return WRONG_MANTISSA_LENGTH;
  }

  while (mantissa_begin < mantissa_end)
  {
    if (string[mantissa_begin] != '.')
    {
      num->mantissa[num->mantissa_length] = string[mantissa_begin] - '0';
      num->mantissa_length += 1;
    }
    mantissa_begin++;
  }


  return OK;
}

int parse_order_part(char *string, long_real_number *num)
{
  if (parse_mantissa_part(string, num) != OK)
  {
    return WRONG_INPUT;
  }

  short int string_length = (short)strlen(string);

  if (num->exp_position == -1)
  {
    num->order_sign = '+';
    num->order = 0;

    return OK;
  }

  short int order_start = (short)(num->exp_position + 1), order_end = string_length;

  if (order_end - order_start > ORDER_MAX_LENGTH)
  {
    return WRONG_ORDER;
  }

  if (string[order_start] == '+' || string[order_start] == '-')
    num->order_sign = string[order_start];
  else
    return WRONG_SIGN;

  order_start++;

  short int string_index = 0;
  char order[ORDER_MAX_LENGTH];

  while (order_start < order_end)
  {
    order[string_index] = string[order_start];
    string_index++;
    order_start++;
  }

  order[string_index] = '\0';

  num->order = (int)atoi(order);

  num->order *= (num->order_sign == '+') ? 1 : -1;

  return OK;
}

error_code convert_long_float_number(long_real_number *num, char *fstring)
{
  num->mantissa_length = 0;
  if (parse_order_part(fstring, num))
    return WRONG_INPUT;

  if (num->point_position == -2)
    num->order += num->mantissa_length;
  else if (num->point_position >= 1 && num->mantissa[0] != 0)
    num->order += num->point_position;
  else
  {
    num->order -= count_lead_nils(num->mantissa, num->mantissa_length) - 1;
    eliminate_lead_nils(num->mantissa, &num->mantissa_length);
  }

  round_mantissa(num, 30);
  eliminate_last_nils(num);

  if (fstring[1] == '.')
    num->order -= 1;
  
  return OK;
}

error_code convert_long_int_number(long_int_number *num, char *istring)
{
  num->length = 0;
  if (istring[0] == '+' || istring[0] == '-')
    num->sign = istring[0];
  else
    return WRONG_SIGN;
      
  for (int i = 1; i < (short)strlen(istring); i++)
  {
    if (istring[i] < '0' || istring[i] > '9')
        return WRONG_INPUT;
    else
    {
        num->number[i - 1] = istring[i] - '0';
        num->length += 1;
    }
  }
  if (num->number[0] == 0)
    eliminate_last_nils_for_num(num);

  return OK;
}