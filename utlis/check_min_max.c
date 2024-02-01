/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:23:20 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/01 11:53:52 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int check_min(t_stack *stack_a)
{
    int min;
    t_stack *tmp;

    tmp = stack_a;
    min = tmp->data;
    while (tmp)
    {
        if (tmp->data < min)
            min = tmp->data;
        tmp = tmp->next;
    }
    return (min);
}
t_stack *check_max(t_stack *stack)
{
    t_stack *max = stack;
    t_stack *current = stack->next;

    while (current != NULL)
    {
        if (current->data > max->data)
        {
            max = current;
        }
        current = current->next;
    }

    return max;
}