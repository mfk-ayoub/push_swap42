/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:26:54 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/09 06:07:14 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
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

static void copy_stack(t_stack *st) {
    int i;
    int size;

    i = 0;
    size = stack_size(st);
    st->tab = (int *)malloc(sizeof(int) * size);
    if (!st->tab)
        return;
    while (i < size)
    {
        st->tab[i] = st->arr[i];
        ++i;
    }
}

void ft_sort_int_tab(t_stack **a)
{
    int i;
    int j;
    int tmp;
    int size;

    i = 0;
    j = 0;
    copy_stack(*a); // Copy stack elements to array
    size = stack_size(*a);
    while (i < size)
    {
        while (j < size)
        {
            if ((*a)->tab[i] > (*a)->tab[j])
            {
                tmp = (*a)->tab[i];
                (*a)->tab[i] = (*a)->tab[j];
                (*a)->tab[j] = tmp;
            }
            j++;
        }
        i++;
        j = i + 1;
    }
}

