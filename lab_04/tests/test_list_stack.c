#include <stdio.h>

#include "../inc/list_stack.h"


int main()
{
    list_stack_t l;
    list_stack_init(&l);

    list_stack_add(&l, 1);
    list_stack_add(&l, 2);
    list_stack_add(&l, 3);

    for (int i = 0; i < 3; i++)
    {
        int x;
        list_stack_pop(&l, &x);
        printf("%d\n", x);
    }

    list_stack_del(&l);

    return 0;
}