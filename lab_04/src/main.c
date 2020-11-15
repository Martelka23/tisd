#include "../inc/menu.h"
#include "../inc/errors.h"
#include "../inc/list_stack.h"
#include "../inc/array_stack.h"
#include "../inc/address_monitoring.h"


int main()
{
    error_code error = OK;
    main_menu_choise choise;

    do
    {
        interface_main_menu();
        scanf("%d", &choise);

        switch (choise)
        {
            case GET_INFO:
                interface_read_me();
                break;
            case STACK_MENU:
                menu_stack();
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