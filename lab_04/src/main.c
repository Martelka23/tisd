#include "../inc/errors.h"
#include "../inc/menu_interfaces.h"
#include "../inc/work_with_list_stack.h"
#include "../inc/work_with_array_stack.h"


int main()
{
    error_code error = OK;
    int choise;

    do
    {
        interface_main_menu();
        scanf("%d", &choise);

        switch (choise)
        {
            case GET_INFO:
                interface_read_me();
                break;
            case ARRAY_STACK:
                error = menu_array_stack();
                break;
            case LIST_STACK:
                error = menu_list_stack();
                break;
            case EXIT:
                break;
            default:
                printf("Неверная команда, будьте внимательнее!\n");
                break;
        }
    } while (!error && choise);

    print_error(error);

    return error;
}