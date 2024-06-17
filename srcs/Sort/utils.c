#include "../includes/push_swap.h"

int    ft_is_sorted(t_stack *stacks, char c)
{
    int i;

    i = 0;
    if (c == 'a')
    {
        while (i < stacks->size_a - 1)
        {
            if (stacks->a[i] > stacks->a[i + 1])
                return (-1);
            i++;
        }
        return (0);
    }
    else
    {
        while (i < stacks->size_b - 1)
        {
            if (stacks->b[i] > stacks->b[i + 1])
                return (-1);
            i++;
        }
        return (0);
    }
}

int   ft_is_largest(t_stack *stacks)
{
    int i;

    i = 0;
    while (i < stacks->size_b)
    {
        if (stacks->b[i] > stacks->a[0])
            return (-1);
        i++;
    }
    return (0);
}

int   ft_is_smallest_a(t_stack *stacks)
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
int   ft_is_smallest(t_stack *stacks)
{
    int i;

    i = 0;
    while (i < stacks->size_b)
    {
        if (stacks->b[i] < stacks->a[0])
            return (-1);
        i++;
    }
    return (0);
}

int   ft_is_largest_b(t_stack *stacks)
{
    int i;

    i = 0;
    while (i < stacks->size_b)
    {
        if (stacks->b[i] > stacks->b[0])
            return (-1);
        i++;
    }
    return (0);
}

int ft_is_smallest_b(t_stack *stacks)
{
    int i;

    i = 0;
    while (i < stacks->size_b)
    {
        if (stacks->b[i] < stacks->b[0])
            return (-1);
        i++;
    }
    return (0);
}

int ft_is_good(t_stack *stacks)
{
    if (ft_is_largest(stacks) == 0 && ft_is_largest_b(stacks) == 0)
        return (0);
    if (ft_is_smallest(stacks) == 0 && ft_is_smallest_b(stacks) == 0)
        return (0);
    if ((stacks->a[0] > stacks->b[0] && stacks->a[0] < stacks->b[stacks->size_b - 1]))
        return (0);
    else
        return (-1);
}
