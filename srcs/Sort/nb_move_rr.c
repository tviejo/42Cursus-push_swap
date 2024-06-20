/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_move_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:32:38 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 15:32:39 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_nb_move_rr(t_stack *stack)
{
	int		i;
	t_stack	temp;
	int		nbmove;
	int		min;

	min = 500;
	temp = create_temp_stack(stack);
	i = 0;
	while (ft_is_good(&temp) != 0 && i < 50 && i <= ft_max_moove(stack))
	{
		ft_rr(&temp, 0);
		nbmove = i + ft_nb_move_temp_rra(&temp, i, ft_max_moove(stack));
		if (nbmove < min)
			min = nbmove;
		nbmove = i + ft_nb_move_temp_rrb(&temp, i, ft_max_moove(stack));
		if (nbmove < min)
			min = nbmove;
		i++;
	}
	ft_free_stacks(&temp);
	stack->moove.rr = i;
	return (i);
}

int	ft_nb_move_rrr(t_stack *stack)
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
		ft_rrr(&temp, 0);
		i++;
		nbmove = i + ft_nb_move_temp_ra(&temp, i, ft_max_moove(stack));
		if (nbmove < min)
			min = nbmove;
		nbmove = i + ft_nb_move_temp_rb(&temp, i, ft_max_moove(stack));
		if (nbmove < min)
			min = nbmove;
	}
	ft_free_stacks(&temp);
	stack->moove.rrr = i;
	return (i);
}
