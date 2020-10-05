#include "../inc/errors.h"
#include "../inc/subscribers.h"
#include "../inc/interface.h"
#include "../inc/sorting.h"

int main()
{
    error_code error = OK;
    int choise = 0;
    subscribers subs;
    subs.length = 0;
    error = read_subs(&subs);

    while (choise != 6 && !error)
    {
        print_main_menu_interface();
        scanf("%d", &choise);
        if (choise == 1)
            print_input_info();
        else if (choise == 2)
            print_all_subscribers(&subs);
        else if (choise == 3)
            error = sort_subs(&subs);
        else if (choise == 4)
            error = add_sub(&subs);
        else if (choise == 5)
            del_sub(&subs);
    }


    // if (!error)
    //     save(&subs);

    return error;
}