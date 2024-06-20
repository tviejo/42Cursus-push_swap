/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:33:09 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 15:33:12 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_max_moove(t_stack *stacks)
{
	int	max;

	max = 0;
	if (stacks->moove.ra > max)
		max = stacks->moove.ra;
	else if (stacks->moove.rra > max)
		max = stacks->moove.rra;
	else if (stacks->moove.rb > max)
		max = stacks->moove.rb;
	else if (stacks->moove.rrb > max)
		max = stacks->moove.rrb;
	else if (stacks->moove.rr > max)
		max = stacks->moove.rr;
	else if (stacks->moove.rrr > max)
		max = stacks->moove.rrr;
	return (max);
}

void	ft_init_moove(t_stack *stacks)
{
	stacks->moove.ra = 500;
	stacks->moove.rra = 500;
	stacks->moove.rb = 500;
	stacks->moove.rrb = 500;
	stacks->moove.rr = 500;
	stacks->moove.rrr = 500;
}

int	ft_is_sorted(t_stack *stacks, char c)
{
	int	i;

	i = 0;
	if (c == 'a')
	{
		while (i < stacks->size_a - 1)
		{
			if (stacks->a[i] > stacks->a[i + 1])
				return (-1);
			i++;
		}
		return (0);
	}
	else
	{
		while (i < stacks->size_b - 1)
		{
			if (stacks->b[i] > stacks->b[i + 1])
				return (-1);
			i++;
		}
		return (0);
	}
}

int	ft_is_good(t_stack *stacks)
{
	int	maxa;
	int	mina;

	maxa = find_largest_stack_a(stacks);
	mina = find_smallest_stack_a(stacks);
	if (stacks->b[0] > maxa && (stacks->a[0] == mina
			&& stacks->a[stacks->size_a - 1] == maxa))
		return (0);
	if (stacks->b[0] < mina && (stacks->a[0] == mina
			&& stacks->a[stacks->size_a - 1] == maxa))
		return (0);
	if ((stacks->b[0] < stacks->a[0]
			&& stacks->b[0] > stacks->a[stacks->size_a - 1])
		&& !((stacks->a[0] == mina)
			&& (stacks->a[stacks->size_a - 1] == maxa))
		&& !((stacks->a[0] == maxa)
			&& (stacks->a[stacks->size_a - 1] == mina)))
		return (0);
	return (-1);
}

int	ft_is_pushable_a(t_stack *temp)
{
	int	maxa;
	int	mina;

	maxa = find_largest_stack_a(temp);
	mina = find_smallest_stack_a(temp);
	if (temp->b[0] > maxa && (temp->a[0] == mina
			&& temp->a[temp->size_a - 1] == maxa))
		return (0);
	if (temp->b[0] < mina && (temp->a[0] == mina
			&& temp->a[temp->size_a - 1] == maxa))
		return (0);
	if ((temp->b[0] < temp->a[0] && temp->b[0] > temp->a[temp->size_a - 1])
		&& !((temp->a[0] == mina) && (temp->a[temp->size_a - 1] == maxa))
		&& !((temp->a[0] == maxa) && (temp->a[temp->size_a - 1] == mina)))
		return (0);
	return (-1);
}
