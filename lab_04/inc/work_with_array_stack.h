#pragma once

#include "array_stack.h"
#include "menu_interfaces.h"
#include "address_monitoring.h"


// Главное меню работы со стэком на массиве
error_code menu_array_stack();
// Копирование адресов из стэка на массиве в мониторинг адресов
void array_stack_addresses_copy(array_stack_t *array_stack, address_monitoring_t *address_monitoring);
// Ввод элементов вручную
error_code array_stack_manual_filling(array_stack_t *array_stack);
// Ввод элементов автоматически
error_code array_stack_auto_filling(array_stack_t *array_stack);
// Вывод элементов стэка
error_code array_stack_output_elems(array_stack_t *array_stack);
// Описание стэка на массиве
void array_stack_description(array_stack_t *array_stack, address_monitoring_t *address_monitoring);