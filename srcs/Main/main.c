/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:48:02 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 16:47:16 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks;

	if (argc == 1)
		return (-1);
	ft_init(argc, argv, &stacks);
	if (ft_is_duplicate(&stacks) == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_free_stacks(&stacks);
		return (-1);
	}
	ft_sort(&stacks);
	ft_free_stacks(&stacks);
	return (0);
}
