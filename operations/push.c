/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:58:28 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/29 05:50:02 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void push_a(t_stack **a, t_stack **b)
{
    if (*b)
    {
        t_stack *tmp = *b;
        *b = (*b)->next;
        if (*b)
            (*b)->prev = NULL;

        tmp->next = *a;
        tmp->prev = NULL;
        if (*a)
            (*a)->prev = tmp;

        *a = tmp;
    }
}

void push_b(t_stack **a, t_stack **b)
{
    if (*a)
    {
        t_stack *tmp = *a;
        *a = (*a)->next;
        if (*a)
            (*a)->prev = NULL;

        tmp->next = *b;
        tmp->prev = NULL;
        if (*b)
            (*b)->prev = tmp;

        *b = tmp;
    }
}

void pa(t_stack **a, t_stack **b)
{
    push_a(a, b);
    ft_putendl_fd("pa", 1);
}

void pb(t_stack **a, t_stack **b)
{
    push_b(a, b);
    ft_putendl_fd("pb", 1);
}
