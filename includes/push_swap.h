/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:48:22 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/16 18:06:26 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>


typedef struct s_stack
{
    int				*a;
    int             *b;
    int             size_a;
    int             size_b;
}	t_stack;

void    ft_sa(t_stack stack);
void    ft_sb(t_stack stack);
void    ft_ss(t_stack stack);
void    ft_pa(t_stack *stack);
void    ft_pb(t_stack *stack);
void    ft_ra(t_stack stack);
void    ft_rb(t_stack stack);
void    ft_rr(t_stack stack);
void    ft_rra(t_stack stack);
void    ft_rrb(t_stack stack);
void    ft_rrr(t_stack stack);


#endif