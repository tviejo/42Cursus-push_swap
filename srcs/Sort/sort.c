/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:48:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 15:30:13 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exec_move(t_stack *stack)
{
	ft_init_moove(stack);
	ft_nb_move_rb(stack);
	ft_nb_move_rrb(stack);
	ft_nb_move_ra(stack);
	ft_nb_move_rra(stack);
	ft_nb_move_rr(stack);
	ft_nb_move_rrr(stack);
}

void	ft_find_fastest_a(t_stack *stack)
{
	t_moove	m;

	ft_exec_move(stack);
	m = stack->moove;
	if (m.rr <= m.rrb && m.rr <= m.ra && m.rr <= m.rra && m.rr <= m.rrr
		&& m.rr <= m.rb)
		ft_rr(stack, 1);
	else if (m.rrr <= m.rrb && m.rrr <= m.ra && m.rrr <= m.rra && m.rrr <= m.rr
		&& m.rrr <= m.rb)
		ft_rrr(stack, 1);
	else if (m.rb <= m.rrb && m.rb <= m.ra && m.rb <= m.rra && m.rb <= m.rrr
		&& m.rb <= m.rr)
		ft_rb(stack, 1);
	else if (m.ra <= m.rrb && m.ra <= m.rb && m.ra <= m.rra && m.ra <= m.rrr
		&& m.ra <= m.rr)
		ft_ra(stack, 1);
	else if (m.rra <= m.rrb && m.rra <= m.rb && m.rra <= m.ra && m.rra <= m.rrr
		&& m.rra <= m.rr)
		ft_rra(stack, 1);
	else
		ft_rrb(stack, 1);
}

void	ft_min_on_top(t_stack *stack)
{
	while (ft_is_smallest_a(stack) != 0)
	{
		if (ft_nb_ra_top(stack) <= ft_nb_rra_top(stack))
			ft_ra(stack, 1);
		else
			ft_rra(stack, 1);
	}
}

void	ft_sort_moyenne(t_stack *stack)
{
	stack->infmedian = 0;
	stack->supmedian = 0;
	stack->moyenne = (find_largest_stack_a(stack)
			+ find_smallest_stack_a(stack)) / 2;
	while (stack->size_a > 3)
	{
		if (stack->a[0] < stack->moyenne)
		{
			while (stack->b[stack->size_b - 1] > stack->moyenne
				&& (stack->supmedian != 0 && stack->infmedian != 0))
				ft_rrb(stack, 1);
			ft_pb(stack, 1);
			stack->infmedian++;
		}
		else
		{
			while (stack->b[0] < stack->moyenne && (stack->supmedian != 0
					&& stack->infmedian != 0))
				ft_rb(stack, 1);
			ft_pb(stack, 1);
			stack->supmedian++;
		}
	}
}

void	ft_sort(t_stack *stack)
{
	if (ft_is_sorted(stack, 'a') == 0)
		return ;
	if (stack->size_a == 2)
	{
		ft_sa(stack, 1);
		return ;
	}
	if (stack->size_a == 3)
	{
		ft_sort_three_a(stack);
		return ;
	}
	ft_sort_moyenne(stack);
	ft_sort_three_a(stack);
	while (stack->size_b > 0)
	{
		while (ft_is_good(stack) != 0)
			ft_find_fastest_a(stack);
		ft_pa(stack, 1);
	}
	ft_min_on_top(stack);
}
