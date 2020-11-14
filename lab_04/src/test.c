#include "../inc/array_stack.h"

int main()
{
    array_stack_t a;
    array_stack_init(&a);

    array_stack_add(&a, 1);
    array_stack_add(&a, 2);
    array_stack_add(&a, 3);

    for (int i = 0; i < 3; i++)
    {
        int x;
        array_stack_pop(&a, &x);
        printf("%d\n", x);
    }

    return 0;
}