#include "../includes/push_swap.h"

int    ft_nb_move_rr(t_stack *stack)
{
    int i;
    t_stack temp;
    int nbmove;
    int min;

    min = 500;
    temp = create_temp_stack(stack);
    i = 0;
    while (ft_is_good(&temp) != 0 && i < 50 )
    {
        ft_rr(&temp, 0);
        nbmove = i + ft_nb_move_temp_rra(&temp, i);
        if (nbmove < min)
            min = nbmove;
        nbmove = i + ft_nb_move_temp_rrb(&temp, i);
        if (nbmove < min)
            min = nbmove;
        i++;
    }
    ft_free_stacks(&temp);
    return (i);
}

int    ft_nb_move_rrr(t_stack *stack)
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
        ft_rrr(&temp, 0);
        i++;
        nbmove = i + ft_nb_move_temp_ra(&temp, i);
        if (nbmove < min)
            min = nbmove;
        nbmove = i + ft_nb_move_temp_rb(&temp, i);
        if (nbmove < min)
            min = nbmove;
    }
    ft_free_stacks(&temp);
    return (i);
}