#pragma once

#include "list_stack.h"
#include "menu_interfaces.h"
#include "address_monitoring.h"


// Главное меню работы со стэком на списке
error_code menu_list_stack();
// Ввод элементов вручную
error_code list_stack_manual_filling(list_stack_t *list_stack, address_monitoring_t *address_monitoring);
// Ввод элементов автоматически
error_code list_stack_auto_filling(list_stack_t *list_stack, address_monitoring_t *address_monitoring);
// Вывод элементов стэка
error_code list_stack_output_elems(list_stack_t *list_stack, address_monitoring_t *address_monitoring);
// Описание стэка на списке
void list_stack_description(list_stack_t *list_stack, address_monitoring_t *address_monitoring);