/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:23:20 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/20 20:10:47 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

t_stack	*check_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*tmp;

	min = stack;
	tmp = stack->next;
	while (tmp != NULL)
	{
		if (tmp->data < min->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*check_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*current;

	if (stack == NULL)
		return (NULL);
	max = stack;
	current = stack->next;
	while (current != NULL)
	{
		if (current->data > max->data)
		{
			max = current;
		}
		current = current->next;
	}
	return (max);
}

int	size_chunk(t_stack **a)
{
	int	size_chunk;

	size_chunk = stack_size(*a);
	if (size_chunk >= 150)
		return (16);
	if (size_chunk >= 20)
		return (5);
	else
		return (4);
}

int	get_numbre_chunk(t_stack **a)
{
	int	num;
	int	size_a;

	num = size_chunk(a);
	size_a = stack_size(*a);
	return (size_a / num);
}

int	find_numbre_in_stack(t_stack *stack, int num)
{
	while (stack)
	{
		if ((stack)->data == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}
