/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:26:54 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 11:32:12 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *stack)
{
    if (stack == NULL || stack->next == NULL)
    {
        return (1);
    }

    while (stack->next != NULL) 
    {
        if (stack->data > stack->next->data)
        {
            return (0); 
        }
        stack = stack->next;
    }
    return (1);
}