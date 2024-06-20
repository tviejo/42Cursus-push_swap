/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:48:22 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/20 16:48:21 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_moove
{
	int		rb;
	int		rrb;
	int		ra;
	int		rra;
	int		rr;
	int		rrr;
}			t_moove;

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		moyenne;
	int		supmedian;
	int		infmedian;
	t_moove	moove;
}			t_stack;

void		ft_sa(t_stack *stack, int mode);
void		ft_sb(t_stack *stack, int mode);
void		ft_ss(t_stack *stack, int mode);
void		ft_pa(t_stack *stack, int mode);
void		ft_pb(t_stack *stack, int mode);
void		ft_ra(t_stack *stack, int mode);
void		ft_rb(t_stack *stack, int mode);
void		ft_rr(t_stack *stack, int mode);
void		ft_rra(t_stack *stack, int mode);
void		ft_rrb(t_stack *stack, int mode);
void		ft_rrr(t_stack *stack, int mode);
int			ft_is_sorted(t_stack *stack, char c);
void		ft_sort(t_stack *stack);
int			ft_is_good(t_stack *stacks);
void		ft_print_stacks(t_stack *stacks);
int			ft_is_smallest_a(t_stack *stacks);
int			ft_is_smallest_b(t_stack *stacks);
int			ft_is_largest(t_stack *stacks);
int			find_largest_stack_b(t_stack *stacks);
int			find_smallest_stack_b(t_stack *stacks);
int			find_largest_stack_a(t_stack *stacks);
int			find_smallest_stack_a(t_stack *stacks);
void		ft_free_stacks(t_stack *stacks);
t_stack		create_temp_stack(t_stack *stacks);
int			ft_is_pushable_a(t_stack *stacks);
int			ft_nb_move_ra(t_stack *stack);
int			ft_nb_move_rb(t_stack *stack);
int			ft_nb_move_rr(t_stack *stack);
int			ft_nb_move_rra(t_stack *stack);
int			ft_nb_move_rrb(t_stack *stack);
int			ft_nb_move_rrr(t_stack *stack);
int			ft_nb_move_temp_ra(t_stack *stack, int i, int imax);
int			ft_nb_move_temp_rb(t_stack *stack, int i, int imax);
int			ft_nb_move_temp_rr(t_stack *stack, int i, int imax);
int			ft_nb_move_temp_rra(t_stack *stack, int i, int imax);
int			ft_nb_move_temp_rrb(t_stack *stack, int i, int imax);
int			ft_nb_move_temp_rrr(t_stack *stack, int i, int imax);
void		ft_push_to_b(t_stack *stack);
void		ft_min_on_top(t_stack *stack);
int			ft_nb_rra(t_stack *stack);
int			ft_nb_rrb(t_stack *stack);
int			ft_nb_ra(t_stack *stack);
int			ft_nb_rb(t_stack *stack);
int			ft_nb_rra_top(t_stack *stack);
int			ft_nb_rrb_top(t_stack *stack);
int			ft_nb_ra_top(t_stack *stack);
int			ft_nb_rb_top(t_stack *stack);
void		ft_find_fastest_b(t_stack *stack);
int			init_stacks(t_stack *stacks, int size, char **argv);
void		ft_print_stacks(t_stack *stacks);
void		ft_free_stacks(t_stack *stacks);
t_stack		create_temp_stack(t_stack *stacks);
void		ft_sort_three_b(t_stack *stack);
void		ft_sort_three_a(t_stack *stack);
void		ft_sort_five_a(t_stack *stack);
int			ft_max_moove(t_stack *stacks);
void		ft_init_moove(t_stack *stacks);
void		ft_free_split(char **str);
int			ft_check_argument(int argc, char **argv);
int			ft_is_duplicate(t_stack *stacks);
int			ft_init(int argc, char **argv, t_stack *stacks);

#endif