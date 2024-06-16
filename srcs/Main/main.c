/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:48:02 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/16 19:12:42 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	init_stacks(t_stack *stacks, int size ,char **argv)
{
	int	i;
	stacks->a = ft_calloc(sizeof(int) , size + 1);
	if (stacks->a == NULL)
		return (free(stacks), -1);
	stacks->b = ft_calloc(sizeof(int) , size + 1);
	if (stacks->b == NULL)
		return (free(stacks), -1);
	stacks->size_a = size;
	stacks->size_b = 0;
	i = 0;
	while (i < size)
	{
		stacks->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}
void ft_print_stacks(t_stack *stacks)
{
	int i;

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
int		ft_check_argument(int argc, char **argv)
{
	int 		i;
	int			j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc < 2 || ft_check_argument(argc, argv) == -1)
		return (ft_putendl_fd("Invalide argument", STDERR_FILENO), -1);
	init_stacks(&stacks, argc - 1, argv);
	ft_print_stacks(&stacks);
	ft_pb(&stacks);
	ft_pb(&stacks);
	ft_pb(&stacks);
	ft_print_stacks(&stacks);
	ft_rra(stacks);
	ft_print_stacks(&stacks);
	ft_rra(stacks);
	ft_print_stacks(&stacks);
	ft_rra(stacks);
	ft_print_stacks(&stacks);
	ft_rrb(stacks);
	ft_print_stacks(&stacks);
	ft_rrb(stacks);
	ft_print_stacks(&stacks);
	ft_rrb(stacks);
	ft_print_stacks(&stacks);
	ft_free_stacks(&stacks);
	return (0);
}
