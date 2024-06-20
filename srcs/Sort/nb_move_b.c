/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_move_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:32:03 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 15:32:05 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_nb_move_rb(t_stack *stack)
{
	int		i;
	t_stack	temp;
	int		min;
	int		nbmove;

	min = 500;
	temp = create_temp_stack(stack);
	i = 0;
	while (ft_is_good(&temp) != 0 && i < 50 && i <= ft_max_moove(stack))
	{
		ft_rb(&temp, 0);
		i++;
		nbmove = i + ft_nb_move_temp_rra(&temp, i, ft_max_moove(stack));
		if (nbmove < min)
			min = nbmove;
	}
	ft_free_stacks(&temp);
	if (min < i)
		i = min;
	stack->moove.rb = i;
	return (i);
}

int	ft_nb_move_rrb(t_stack *stack)
{
	int		i;
	t_stack	temp;
	int		min;
	int		nbmove;

	min = 500;
	temp = create_temp_stack(stack);
	i = 0;
	while (ft_is_good(&temp) != 0 && i < 50 && i <= ft_max_moove(stack))
	{
		ft_rrb(&temp, 0);
		i++;
		nbmove = i + ft_nb_move_temp_ra(&temp, i, ft_max_moove(stack));
		if (nbmove < min)
			min = nbmove;
	}
	ft_free_stacks(&temp);
	if (min < i)
		i = min;
	stack->moove.rrb = i;
	return (i);
}
