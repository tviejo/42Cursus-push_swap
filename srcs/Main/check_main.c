/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:59:40 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/21 13:08:46 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_argument(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && ft_isdigit(argv[i][j]) == 0 && argv[i][0] != '-'
					&& argv[i][0] != '+')
				return (-1);
			if (ft_isdigit(argv[i][j]) == 0 && j != 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_is_duplicate(t_stack *stacks)
{
	int	i;
	int	j;

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

int	ft_init(int argc, char **argv, t_stack *stacks)
{
	char	**words;
	int		nbword;

	if (argc == 2)
	{
		words = ft_split(argv[1], ' ');
		nbword = ft_count_words(argv[1], ' ');
		if (nbword == 0 || ft_check_argument(nbword, words) == -1)
		{
			ft_free_split(words);
			return (ft_putendl_fd("Error", STDERR_FILENO), exit(-1), -1);
		}
		init_stacks(stacks, nbword, words, 2);
	}
	else
	{
		if (ft_check_argument(argc - 1, &argv[1]) == -1)
			return (ft_putendl_fd("Error", STDERR_FILENO), exit(-1), -1);
		init_stacks(stacks, argc - 1, &argv[1], 1);
	}
	return (0);
}
