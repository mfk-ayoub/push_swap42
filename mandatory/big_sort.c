/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:59:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/15 08:40:41 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_and_push(t_stack **a, t_stack **b, int chunk, int max)
{
    int i;
    int half;

    half = chunk / 2;
    i = 0;
    while (*a && i < chunk)
    {
        if ((*a)->data <= max)
        {
            if ((*a)->data <= max - half)
                pb(a, b); 
            {
                pb(a, b);
                rb(b);
            }
            i++;
        }
        else
            ra(a); 
    }
}

void sort_try(t_stack **a, t_stack **b)
{
    int *array;
    int size;
    int i;
    int chunk_size;
    int chunk; 

    array = array_dup(*a);
    ft_sort_int_tab(array, stack_size(*a));
    size = stack_size(*a);
    chunk_size = size_chunk(a);
    chunk = size / chunk_size;
    i = chunk;
    while(i <= size)
    {
        check_and_push(a, b, chunk, i);
        if (!stack_size(*a))
            break ;
        i += chunk;
    }
    free(array);
}




