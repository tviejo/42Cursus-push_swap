/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:48:02 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/19 13:36:22 by tviejo           ###   ########.fr       */
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
		stacks->a[i] = ft_atoi(argv[i]);
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

int		ft_check_argument(int argc, char **argv)
{
	int 		i;
	int			j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == '-')
				return (-1);
			if (ft_isdigit(argv[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_is_duplicate(t_stack *stacks)
{
	int i;
	int j;

	i = 0;
	while (i < stacks->size_a)
	{
		j = i + 1;
		while (j < stacks->size_a)
		{
			if (stacks->a[i] == stacks->a[j])
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
	char **words;
	int	nbword;

	if (argc == 1)
		return (ft_putendl_fd("No argument", STDERR_FILENO), -1);
	if (argc == 2)
	{
		words = ft_split(argv[1], ' ');
		nbword = ft_count_words(argv[1], ' ');
		if (ft_check_argument(nbword, words) == -1)
			return (ft_putendl_fd("Invalide argument", STDERR_FILENO), -1);
		init_stacks(&stacks, nbword, words);
	}
	else
	{
		if (ft_check_argument(argc - 1, &argv[1]) == -1)
			return (ft_putendl_fd("Invalide argument", STDERR_FILENO), -1);
		init_stacks(&stacks, argc - 1, &argv[1]);
	}
	if (ft_is_duplicate(&stacks) == -1)
		return (ft_putendl_fd("Duplicate argument", STDERR_FILENO), -1);
	ft_sort(&stacks);
	ft_free_stacks(&stacks);
	return (0);
}
