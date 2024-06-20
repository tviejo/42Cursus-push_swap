/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:47:50 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 14:58:37 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack, char c)
{
	int	tmp;

	if (c == 'a')
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	else
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
}

void	ft_sa(t_stack *stack, int mode)
{
	ft_swap(stack, 'a');
	if (mode == 1)
		ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stack *stack, int mode)
{
	ft_swap(stack, 'b');
	if (mode == 1)
		ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stack *stack, int mode)
{
	ft_swap(stack, 'a');
	ft_swap(stack, 'b');
	if (mode == 1)
		ft_putendl_fd("ss", 1);
}
