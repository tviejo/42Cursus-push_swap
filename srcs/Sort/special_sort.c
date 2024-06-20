/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:32:51 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 15:32:53 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three_a(t_stack *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[0] > stack->a[2])
		ft_ra(stack, 1);
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2]
		&& stack->a[0] < stack->a[2])
		ft_sa(stack, 1);
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[0] < stack->a[2])
	{
		ft_rra(stack, 1);
		ft_sa(stack, 1);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ft_sa(stack, 1);
		ft_rra(stack, 1);
	}
	else if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2]
		&& stack->a[0] > stack->a[2])
		ft_rra(stack, 1);
}

void	ft_sort_three_b(t_stack *stack)
{
	if (stack->b[0] < stack->b[1] && stack->b[1] > stack->b[2]
		&& stack->b[0] < stack->b[2])
		ft_rb(stack, 1);
	else if (stack->b[0] < stack->b[1] && stack->b[1] > stack->b[2]
		&& stack->b[0] > stack->b[2])
		ft_sb(stack, 1);
	else if (stack->b[0] > stack->b[1] && stack->b[1] < stack->b[2]
		&& stack->b[0] > stack->b[2])
	{
		ft_rrb(stack, 1);
		ft_sb(stack, 1);
	}
	else if (stack->b[0] < stack->b[1] && stack->b[1] < stack->b[2])
	{
		ft_sb(stack, 1);
		ft_rrb(stack, 1);
	}
	else if (stack->b[0] > stack->b[1] && stack->b[1] < stack->b[2]
		&& stack->b[0] < stack->b[2])
		ft_rrb(stack, 1);
}
