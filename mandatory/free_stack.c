/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:55:34 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/02 10:27:44 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void free_stack_node(t_stack *node)
// {
//     free(node);
// }

void free_stack(t_stack *stack)
{
    t_stack *current = stack;
    t_stack *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}