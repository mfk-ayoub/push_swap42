/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:58:28 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 11:10:30 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void    push_b(t_stack **a, t_stack **b)
{
    if (*a)
    {
        t_stack *tmp = *a;
        *a = (*a)->next;
        if (*stack_a)
            (*a)->prev = NULL;

        tmp->next = *b;
        tmp->prev = NULL;
        if (*b)
            (*b)->prev = tmp;

        *b = tmp;
    }
}