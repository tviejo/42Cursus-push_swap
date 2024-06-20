/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_move_a_temp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:31:55 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 15:31:56 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_nb_ra_top(t_stack *stack)
{
	int		i;
	t_stack	temp;

	temp = create_temp_stack(stack);
	i = 0;
	while (ft_is_smallest_a(&temp) != 0 && i < 250)
	{
		ft_ra(&temp, 0);
		i++;
	}
	ft_free_stacks(&temp);
	return (i);
}

int	ft_nb_rra_top(t_stack *stack)
{
	int		i;
	t_stack	temp;

	temp = create_temp_stack(stack);
	i = 0;
	while (ft_is_smallest_a(&temp) != 0 && i < 250)
	{
		ft_rra(&temp, 0);
		i++;
	}
	ft_free_stacks(&temp);
	return (i);
}

int	ft_nb_move_temp_ra(t_stack *stack, int i, int imax)
{
	t_stack	temp;

	temp = create_temp_stack(stack);
	while (ft_is_good(&temp) != 0 && i < 50 && i <= imax)
	{
		ft_ra(&temp, 0);
		i++;
	}
	ft_free_stacks(&temp);
	return (i);
}

int	ft_nb_move_temp_rra(t_stack *stack, int i, int imax)
{
	t_stack	temp;

	temp = create_temp_stack(stack);
	while (ft_is_good(&temp) != 0 && i < 50 && i <= imax)
	{
		ft_rra(&temp, 0);
		i++;
	}
	ft_free_stacks(&temp);
	return (i);
}
