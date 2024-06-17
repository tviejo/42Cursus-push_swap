/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:48:14 by tviejo            #+#    #+#             */
/*   Updated: 2024/06/16 23:02:36 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int    ft_nb_move(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    while (stack->a[0] > stack->b[i] && stack->a[0] < stack->b[i + 1])
        i++;
    j = 0;
    while (stack->a[0] > stack->b[stack->size_b - j] && stack->a[0] < stack->b[stack->size_b - j - 1])
        j++;
    if (i < j)
        return (i);
    else
        return (j);
}
void    ft_find_fastest_b(t_stack *stack)
{
    int i;
    int j;

    i = 0;
    if (ft_is_largest(stack) == 0 || ft_is_smallest_b(stack) == 0)
    {
        ft_rb(stack);
        return ;
    }
    while (!(stack->a[0] > stack->b[i] && stack->a[0] < stack->b[i + 1]) && i < stack->size_b - 1)
        i++;
    j = 0;
    while (!(stack->a[0] > stack->b[stack->size_b - j] && stack->a[0] < stack->b[stack->size_b - j - 1]) && j < stack->size_b - 1)
        j++;
    if (i <= j)
        ft_rb(stack);
    else
        ft_rrb(stack);
}
int ft_find_closest(t_stack *stack)
{
    int i;
    while (i < stack->size_a)
    {
        if (stack->a[i] < stack->b[0] || stack->a[i] > stack->b[stack->size_b])
            break;
        if (stack->a[i] < stack->b[0] && stack->a[i] > stack->b[stack->size_b])
            break;
        if (stack->a[i] > stack->b[0] && stack->a[i] < stack->b[stack->size_b])
            break;
        i++;
    }
    if (i < ft_nb_move(stack))
        return (0);
    return (-1);
}

void    ft_sort(t_stack *stack)
{
    ft_pb(stack);
    while (stack->size_a > 0)
    {
        while (ft_is_good(stack) != 0)
        {
            if (ft_find_closest(stack) == 0)
                ft_ra(stack);
            else
                ft_find_fastest_b(stack);
        
        }
        ft_pb(stack);
    }
    while (stack->size_b > 0)
        ft_pa(stack);
    while (ft_is_smallest_a(stack) != 0)
        ft_ra(stack);
}