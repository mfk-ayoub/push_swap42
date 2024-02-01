/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 06:23:22 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/01 06:44:19 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_node(int value)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (node == NULL)
    {
        return NULL;
    }
    node->data = value;
    node->next = NULL;
    node->prev = NULL;
    return (stack_node);
}

void push(t_stack **s, int nb)
{  
    t_stack *top;
    
    top = create_node(nb);
    
    if (s)
    {
        top->next = *s;
        top->prev = NULL;
        if (*s)
        {
            (*s)->prev = top;
        }
        *s = top;
    }
}