/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:31:28 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 11:17:59 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

t_stack *init_stack(int value)
{
    t_stack *stack_node = malloc(sizeof(t_stack));
    if (stack_node == NULL)
    {
        return NULL;
    }
    stack_node->data = value;
    stack_node->next = NULL;
    stack_node->prev = NULL;
    return (stack_node);
}

t_stack *add_stack(t_stack *stack, int value)
{
    t_stack *tmp = stack;
    t_stack *new_node = init_stack(value);
    if (stack == NULL)
        return (new_node);
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
    new_node->prev = tmp;
    return (stack);
}

t_stack *init_stack_a(int len, char **av)
{
    int i = 0;
    t_stack *stack_a = NULL;

    while (i < len)
    {
        stack_a = add_stack(stack_a, ft_atoi(av[i]));
        i++;
    }
    if (stack_size(stack_a) == 1)
    {
        ft_putstr_fd("Error1\n", 2);
        exit(1); 
    }
    return (stack_a);
}

// void print_stack(t_stack *stack)
// {
//     while (stack != NULL)
//     {
//         printf("%d ", stack->data);
//         stack = stack->next;
//     }
//     printf("\n");
// }
