/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:57:50 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 11:11:16 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void rotate(t_stack **stack)
{
    if (*stack && (*stack)->next)
    {
        t_stack *first = *stack;
        t_stack *last = *stack;

        while (last->next)
            last = last->next;

        last->next = first;
        first->prev = last;
        *stack = first->next;
        first->next = NULL;
        (*stack)->prev = NULL;
    }
}
void rotate_a(t_stack **a)
{
    rotate(a);
    ft_putendl_fd("ra", 1);
}
void rotate_b(t_stack **b)
{
    rotate(b);
    ft_putendl_fd("rb", 1);
}

void rr(t_stack **a, t_stack **b)
{
    rotate_a(a);
    rotate_b(b);
    ft_putendl_fd("rr", 1);
}