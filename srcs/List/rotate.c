/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:47:33 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 14:54:19 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack *stack, char c)
{
	int	tmp;
	int	i;

	i = 0;
	if (c == 'a')
	{
		tmp = stack->a[0];
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a[stack->size_a - 1] = tmp;
	}
	else
	{
		tmp = stack->b[0];
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b[stack->size_b - 1] = tmp;
	}
}

void	ft_ra(t_stack *stack, int mode)
{
	ft_rotate(stack, 'a');
	if (mode == 1)
		ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stack *stack, int mode)
{
	ft_rotate(stack, 'b');
	if (mode == 1)
		ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stack *stack, int mode)
{
	ft_rotate(stack, 'a');
	ft_rotate(stack, 'b');
	if (mode == 1)
		ft_putendl_fd("rr", 1);
}
