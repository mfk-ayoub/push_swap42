/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:26:54 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/09 22:24:19 by ayel-mou         ###   ########.fr       */
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

int *array_dup(t_stack *s)
{
	int i;
	int len; 
	int *array;
	
	i = 0;
	len = stack_size(s);
	array = (int *)malloc (sizeof(int) * len);
	while (s)
	{
		array[i] = s->data;
		i++;
		s = s->next;
	}
	return (array);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int tmp;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}


