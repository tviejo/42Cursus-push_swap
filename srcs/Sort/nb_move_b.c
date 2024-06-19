#include "../includes/push_swap.h"

int    ft_nb_move_rb(t_stack *stack)
{
    int i;
    t_stack temp;
    int min;
    int nbmove;

    min = 500;
    temp = create_temp_stack(stack);
    i = 0;
    while (ft_is_good(&temp) != 0 && i < 50)
    {
        ft_rb(&temp, 0);
        i++;
        nbmove = i + ft_nb_move_temp_rra(&temp, i);
        if (nbmove < min)
            min = nbmove;
        
    }
    ft_free_stacks(&temp);
    if (min < i)
        return (min);
    return (i);
}

int    ft_nb_move_rrb(t_stack *stack)
{
    int i;
    t_stack temp;
    int min;
    int nbmove;

    min = 500;
    temp = create_temp_stack(stack);
    i = 0;
    while (ft_is_good(&temp) != 0 && i < 50)
    {
        ft_rrb(&temp, 0);
        i++;
        nbmove = i + ft_nb_move_temp_ra(&temp, i);
        if (nbmove < min)
            min = nbmove;
    }
    ft_free_stacks(&temp);
    if (min < i)
        return (min);
    return (i);
}