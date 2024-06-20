/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:47:41 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 14:54:16 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rrotate(t_stack *stack, char c)
{
	int	tmp;
	int	i;

	i = 1;
	if (c == 'a')
	{
		tmp = stack->a[stack->size_a - 1];
		while (i < stack->size_a)
		{
			stack->a[stack->size_a - i] = stack->a[stack->size_a - i - 1];
			i++;
		}
		stack->a[0] = tmp;
	}
	else
	{
		tmp = stack->b[stack->size_b - 1];
		while (i < stack->size_b)
		{
			stack->b[stack->size_b - i] = stack->b[stack->size_b - i - 1];
			i++;
		}
		stack->b[0] = tmp;
	}
}

void	ft_rra(t_stack *stack, int mode)
{
	ft_rrotate(stack, 'a');
	if (mode == 1)
		ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stack *stack, int mode)
{
	ft_rrotate(stack, 'b');
	if (mode == 1)
		ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_stack *stack, int mode)
{
	ft_rrotate(stack, 'a');
	ft_rrotate(stack, 'b');
	if (mode == 1)
		ft_putendl_fd("rrr", 1);
}
