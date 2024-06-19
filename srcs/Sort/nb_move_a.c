#include "../includes/push_swap.h"

int    ft_nb_move_ra(t_stack *stack)
{
    int i;
    t_stack temp;
    int min;
    int nbmove;

    min = 500;
    temp = create_temp_stack(stack);
    i = 0;
    while (ft_is_good(&temp) != 0 && i < 50 && i <= ft_max_moove(stack))
    {
        ft_ra(&temp, 0);
        i++;
        nbmove = i + ft_nb_move_temp_rrb(&temp, i, ft_max_moove(stack));
        if (nbmove < min)
            min = nbmove;
    }
    ft_free_stacks(&temp);
    if (min < i)
        i = min;
    stack->moove.ra = i;
    return (i);
}

int    ft_nb_move_rra(t_stack *stack)
{
    int i;
    t_stack temp;
    int min;
    int nbmove;

    min = 500;
    temp = create_temp_stack(stack);
    i = 0;
    while (ft_is_good(&temp) != 0 && i < 50 && i <= ft_max_moove(stack))
    {
        ft_rra(&temp, 0);
        i++;
        nbmove = i + ft_nb_move_temp_rb(&temp, i, ft_max_moove(stack));
        if (nbmove < min)
            min = nbmove;
    }
    ft_free_stacks(&temp);
    if (min < i)
        i = min;
    stack->moove.rra = i;
    return (i);
}

int    ft_nb_ra(t_stack *stack)
{
    int i;
    t_stack temp;

    temp = create_temp_stack(stack);
    i = 0;
    while (ft_is_pushable_a(&temp) != 0 && i < 250)
    {
        ft_ra(&temp, 0);
        i++;
    }
    ft_free_stacks(&temp);
    return (i);
}

int    ft_nb_rra(t_stack *stack)
{
    int i;
    t_stack temp;

    temp = create_temp_stack(stack);
    i = 0;
    while (ft_is_pushable_a(&temp) != 0 && i < 250)
    {
        ft_rra(&temp, 0);
        i++;
    }
    ft_free_stacks(&temp);
    return (i);
}