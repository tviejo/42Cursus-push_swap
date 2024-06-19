/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:48:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/19 21:16:30 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    ft_find_fastest_b(t_stack *stack)
{
    int rb;
    int rrb;
    int ra;
    int rra;
    int rr;
    int rrr;

    rb = ft_nb_move_rb(stack);
    rrb = ft_nb_move_rrb(stack);
    ra = ft_nb_move_ra(stack);
    rra = ft_nb_move_rra(stack);
    rr = ft_nb_move_rr(stack);
    rrr = ft_nb_move_rrr(stack);
    //printf("rb:%d RRb:%d ra:%d rra:%d rr:%d rrr:%d\n", rb, rrb, ra, rra, rr, rrr);
    if (rr <= rrb && rr <= ra && rr <= rra && rr <= rrr && rr <= rb)
        ft_rr(stack, 1);
    else if (rrr <= rrb && rrr <= ra && rrr <= rra && rrr <= rr && rrr <= rb)
        ft_rrr(stack, 1);
    else if (rb <= rrb && rb <= ra && rb <= rra && rb <= rrr && rb <= rr)
        ft_rb(stack, 1);
    else if (ra <= rrb && ra <= rb && ra <= rra && ra <= rrr && ra <= rr)
        ft_ra(stack, 1);
    else if (rra <= rrb && rra <= rb && rra <= ra && rra <= rrr && rra <= rr)
        ft_rra(stack, 1);
    else
        ft_rrb(stack, 1);
}

void    ft_sort_three_b(t_stack *stack)
{
    
	if (stack->b[0] < stack->b[1] && stack->b[1] > stack->b[2] && stack->b[0] < stack->b[2])
		ft_rb(stack, 1);
    else if (stack->b[0] < stack->b[1] && stack->b[1] > stack->b[2] && stack->b[0] > stack->b[2])
		ft_sb(stack, 1);
	else if (stack->b[0] > stack->b[1] && stack->b[1] < stack->b[2] && stack->b[0] > stack->b[2])
	{
		ft_rrb(stack, 1);
		ft_sb(stack, 1);
	}
    else if (stack->b[0] < stack->b[1] && stack->b[1] < stack->b[2])
	{
		ft_sb(stack, 1);
		ft_rrb(stack, 1);
	}
	else if (stack->b[0] > stack->b[1] && stack->b[1] < stack->b[2] && stack->b[0] < stack->b[2])
		ft_rrb(stack, 1);
}

void    ft_sort_three_a(t_stack *stack)
{
    
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && stack->a[0] > stack->a[2])
		ft_ra(stack, 1);
    else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2] && stack->a[0] < stack->a[2])
		ft_sa(stack, 1);
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && stack->a[0] < stack->a[2])
	{
		ft_rra(stack, 1);
		ft_sa(stack, 1);
	}
    else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2] && stack->a[0] > stack->a[2])
		ft_rra(stack, 1);
}

void    ft_push_to_a(t_stack *stack)
{
    while (stack->size_b > 0)
    {
        if (ft_nb_ra(stack) == 0 || ft_nb_rra(stack) == 0)
            ft_pa(stack, 1);
        else if (ft_nb_ra(stack) <= ft_nb_rra(stack))
            ft_ra(stack, 1);
        else
            ft_rra(stack, 1);
    }
    while (ft_is_smallest_a(stack) != 0)
    {
        if (ft_nb_ra_top(stack) <= ft_nb_rra_top(stack))
            ft_ra(stack, 1);
        else
            ft_rra(stack, 1);
    }
}

void    ft_sort(t_stack *stack)
{
    if (ft_is_sorted(stack, 'a') == 0)
        return ;
    ft_pb(stack, 1);
    ft_pb(stack, 1);
    ft_pb(stack, 1);
    ft_sort_three_b(stack);
    while (stack->size_a > 3)
    {
        while (ft_is_good(stack) != 0)
        {
            //ft_print_stacks(stack);
            ft_find_fastest_b(stack);
        }
        ft_pb(stack, 1);
    }
    ft_sort_three_a(stack);
    ft_push_to_a(stack);
}
