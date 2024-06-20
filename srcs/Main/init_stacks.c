/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:33:25 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 16:54:18 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stacks(t_stack *stacks, int size, char **argv)
{
	int	i;

	stacks->a = ft_calloc(sizeof(int), size + 1);
	if (stacks->a == NULL)
		return (free(stacks), -1);
	stacks->b = ft_calloc(sizeof(int), size + 1);
	if (stacks->b == NULL)
		return (free(stacks), -1);
	stacks->size_a = size;
	stacks->size_b = 0;
	i = 0;
	while (i < size)
	{
		if (ft_atol(argv[i]) >= 0 && ft_atol(argv[i]) <= INT_MAX)
			stacks->a[i] = ft_atol(argv[i]);
		else
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (ft_free_stacks(stacks), exit(-1), -1);
		}
		i++;
	}
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
