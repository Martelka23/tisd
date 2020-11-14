#include "../inc/list.h"
#include "../inc/errors.h"
#include "../inc/vector.h"
#include "../inc/interface.h"
#include "../inc/matrix_io.h"
#include "../inc/work_with_file.h"
#include "../inc/matrix_calculate.h"


int main()
{
    error_code error = OK;

    int choise = -1;

    common_matrix matrix1 = { NULL, 0, 0 };
    common_matrix matrix2 = { NULL, 0, 0 };
    sparse_matrix smatrix1 = { NULL, NULL, NULL };
    sparse_memory_allocation(&smatrix1);
    sparse_matrix smatrix2 = { NULL, NULL, NULL };
    sparse_memory_allocation(&smatrix2);

    print_name_of_program();

    while (choise && !error)
    {
        print_main_menu();
        scanf("%d", &choise);

        if (choise == 0)
            continue;
        else if (choise == 1)
            print_input_info();
        else if (choise == 2)
            matrix_main_create();
        else if (choise == 3)
            matrix_main_read(&matrix1, &matrix2, &smatrix1, &smatrix2);
        else if (choise == 4)
            matrix_input_menu(&matrix1, &matrix2, &smatrix1, &smatrix2);
        else if (choise == 5)
            matrix_output_menu(&matrix1, &matrix2, &smatrix1, &smatrix2);
        else if (choise == 6)
            matrix_menu_calculate(&matrix1, &matrix2, &smatrix1, &smatrix2);
        else
            printf("Неизвестная команда!\n");

        printf("\n");
        
    }

    common_memory_deallocation(matrix1.m, &matrix1.M);
    common_memory_deallocation(matrix2.m, &matrix2.M);
    sparse_memory_deallocation(&smatrix1);
    sparse_memory_deallocation(&smatrix2);
    printf("Память отчищена :3\n");

    print_error(error);

    return error;
}