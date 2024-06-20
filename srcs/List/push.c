/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:47:24 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 14:54:24 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pb(t_stack *stack, int mode)
{
	int	i;
	int	tmp;

	if (stack->size_a == 0)
		return ;
	i = 0;
	tmp = stack->a[0];
	while (i < stack->size_a)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a] = 0;
	stack->a[stack->size_a - 1] = 0;
	i = stack->size_b;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = tmp;
	stack->size_a--;
	stack->size_b++;
	if (mode == 1)
		ft_putendl_fd("pb", 1);
}

void	ft_pa(t_stack *stack, int mode)
{
	int	i;
	int	tmp;

	if (stack->size_b == 0)
		return ;
	i = 0;
	tmp = stack->b[0];
	while (i < stack->size_b)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b] = 0;
	stack->b[stack->size_b - 1] = 0;
	i = stack->size_a;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = tmp;
	stack->size_a++;
	stack->size_b--;
	if (mode == 1)
		ft_putendl_fd("pa", 1);
}
