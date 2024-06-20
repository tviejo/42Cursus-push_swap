/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_move_b_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:32:16 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 15:32:18 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_nb_rb(t_stack *stack)
{
	int		i;
	t_stack	temp;

	temp = create_temp_stack(stack);
	i = 0;
	while (stack->b[0] != find_largest_stack_b(stack) && i < 250)
	{
		ft_rb(&temp, 0);
		i++;
	}
	ft_free_stacks(&temp);
	return (i);
}

int	ft_nb_rrb(t_stack *stack)
{
	int		i;
	t_stack	temp;

	temp = create_temp_stack(stack);
	i = 0;
	while (stack->b[0] != find_largest_stack_b(stack) && i < 250)
	{
		ft_rrb(&temp, 0);
		i++;
	}
	ft_free_stacks(&temp);
	return (i);
}

int	ft_nb_move_temp_rb(t_stack *stack, int i, int imax)
{
	t_stack	temp;

	temp = create_temp_stack(stack);
	while (ft_is_good(&temp) != 0 && i < 50 && i <= imax)
	{
		ft_rb(&temp, 0);
		i++;
	}
	ft_free_stacks(&temp);
	return (i);
}

int	ft_nb_move_temp_rrb(t_stack *stack, int i, int imax)
{
	t_stack	temp;

	temp = create_temp_stack(stack);
	while (ft_is_good(&temp) != 0 && i < 50 && i <= imax)
	{
		ft_rrb(&temp, 0);
		i++;
	}
	ft_free_stacks(&temp);
	return (i);
}
