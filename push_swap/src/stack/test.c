#include <stdio.h>
#include "stack.h"

int main(void)
{
    t_stack *a;
    t_stack *b;

    a = stack_create();
    b = stack_create();

    stack_push_back(a, 4);
    stack_push_back(a, 5);
    stack_push_back(a, 6);
    stack_push_back(a, 7);
    stack_push_back(a, 8);

    stack_push_back(b, 4);
    stack_push_back(b, 5);
    stack_push_back(b, 6);
    stack_push_back(b, 7);
    stack_push_back(b, 8);

    stack_shift(a, b);
    stack_shift(a, b);

    stack_print(a);
    printf("\n");
    stack_print(b);
    printf("\n");

    stack_rotate(a);
    stack_rotate(a);
    stack_rotate(a);
    stack_rotate(a);
    stack_reverse_rotate(a);
    stack_reverse_rotate(a);
    stack_reverse_rotate(a);
    stack_reverse_rotate(a);
    stack_print(a);
    printf("\n");

    stack_destroy(&a);
    stack_destroy(&b);
    return 0;
}