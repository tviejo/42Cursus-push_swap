/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:59:49 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 17:59:51 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_movement(t_stack *stacks, char *line)
{
	if (ft_strncmp(line, "sa\n", ft_strlen(line)) == 0)
		ft_sa(stacks, 0);
	else if (ft_strncmp(line, "sb\n", ft_strlen(line)) == 0)
		ft_sb(stacks, 0);
	else if (ft_strncmp(line, "ss\n", ft_strlen(line)) == 0)
		ft_ss(stacks, 0);
	else if (ft_strncmp(line, "pa\n", ft_strlen(line)) == 0)
		ft_pa(stacks, 0);
	else if (ft_strncmp(line, "pb\n", ft_strlen(line)) == 0)
		ft_pb(stacks, 0);
	else if (ft_strncmp(line, "ra\n", ft_strlen(line)) == 0)
		ft_ra(stacks, 0);
	else if (ft_strncmp(line, "rb\n", ft_strlen(line)) == 0)
		ft_rb(stacks, 0);
	else if (ft_strncmp(line, "rr\n", ft_strlen(line)) == 0)
		ft_rr(stacks, 0);
	else if (ft_strncmp(line, "rra\n", ft_strlen(line)) == 0)
		ft_rra(stacks, 0);
	else if (ft_strncmp(line, "rrb\n", ft_strlen(line)) == 0)
		ft_rrb(stacks, 0);
	else if (ft_strncmp(line, "rrr\n", ft_strlen(line)) == 0)
		ft_rrr(stacks, 0);
	else
		return (-1);
	return (0);
}

int	ft_read_arg(t_stack *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (ft_find_movement(stacks, line) == -1)
		{
			free(line);
			ft_putendl_fd("Error", STDERR_FILENO);
			return (-1);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (ft_is_sorted(stacks, 'a') == 0 && stacks->size_b == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}

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
	ft_read_arg(&stacks);
	ft_print_stacks(&stacks);
	ft_free_stacks(&stacks);
	return (0);
}
