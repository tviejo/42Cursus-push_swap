#include "../includes/push_swap.h"

int ft_is_smallest_a(t_stack *stacks)
{
    int i;

    i = 0;
    while (i < stacks->size_a)
    {
        if (stacks->a[i] < stacks->a[0])
            return (-1);
        i++;
    }
    return (0);
}

int find_largest_stack_b(t_stack *stacks)
{
    int i;
    int max;

    max = INT_MIN;
    i = 0;
    while (i < stacks->size_b)
    {
        if (stacks->b[i] > max)
            max = stacks->b[i];
        i++;
    }
    return (max);
}

int find_smallest_stack_b(t_stack *stacks)
{
    int i;
    int min;

    min = INT_MAX;
    i = 0;
    while (i < stacks->size_b)
    {
        if (stacks->b[i] < min)
            min = stacks->b[i];
        i++;
    }
    return (min);
}

int find_largest_stack_a(t_stack *stacks)
{
    int i;
    int max;

    max = INT_MIN;
    i = 0;
    while (i < stacks->size_a)
    {
        if (stacks->a[i] > max)
            max = stacks->a[i];
        i++;
    }
    return (max);
}

int find_smallest_stack_a(t_stack *stacks)
{
    int i;
    int min;

    min = INT_MAX;
    i = 0;
    while (i < stacks->size_a)
    {
        if (stacks->a[i] < min)
            min = stacks->a[i];
        i++;
    }
    return (min);
}