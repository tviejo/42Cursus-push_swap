/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:33:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/23 13:25:41 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	init_size_stack(t_stack *stacks, int size)
{
	stacks->a = ft_calloc(sizeof(int), size + 1);
	if (stacks->a == NULL)
		return (free(stacks), -1);
	stacks->b = ft_calloc(sizeof(int), size + 1);
	if (stacks->b == NULL)
		return (free(stacks), -1);
	stacks->size_a = size;
	stacks->size_b = 0;
	return (0);
}

int	init_stacks(t_stack *stack, int size, char **argv, int mode)
{
	int	i;

	init_size_stack(stack, size);
	i = -1;
	while (++i < size)
	{
		if (ft_atol(argv[i]) >= INT_MIN && ft_atol(argv[i]) <= INT_MAX)
			stack->a[i] = ft_atol(argv[i]);
		else
		{
			if (mode == 2)
				ft_free_split(argv);
			ft_putendl_fd("Error", 2);
			return (ft_free_stacks(stack), exit(-1), -1);
		}
	}
	if (mode == 2)
		ft_free_split(argv);
	if (size <= 1)
		return (ft_free_stacks(stack), exit(-1), -1);
	if (ft_is_duplicate(stack) == -1)
		return (ft_putendl_fd("Error", 2), ft_free_stacks(stack), exit(-1), -1);
	return (0);
}

void	ft_print_stacks(t_stack *stacks)
{
	int	i;

	i = 0;
	ft_printf("\n\n");
	while (i < stacks->size_a || i < stacks->size_b)
	{
		ft_printf("%d    %d\n", stacks->a[i], stacks->b[i]);
		i++;
	}
}

void	ft_free_stacks(t_stack *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
}

t_stack	create_temp_stack(t_stack *stacks)
{
	t_stack	temp;

	temp.a = ft_calloc(sizeof(int), stacks->size_a + stacks->size_b);
	ft_memcpy(temp.a, stacks->a, sizeof(int) * stacks->size_a);
	temp.b = ft_calloc(sizeof(int), stacks->size_a + stacks->size_b);
	ft_memcpy(temp.b, stacks->b, sizeof(int) * stacks->size_b);
	temp.size_a = stacks->size_a;
	temp.size_b = stacks->size_b;
	return (temp);
}
