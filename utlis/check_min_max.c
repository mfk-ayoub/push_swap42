/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 11:23:20 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/13 05:09:35 by ayel-mou         ###   ########.fr       */
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
	if (stack  == NULL)
		return (NULL);
	t_stack	*max;
	t_stack	*current;

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

int	size_array(t_stack **a)
{
	int size_array;

	size_array = stack_size(*a);
	if (size_array >= 20 && size_array <= 99)
		return (4);
    else if (size_array >= 100 && size_array < 500)
        return (5);
	else if (size_array >= 500)
		return (11);
    return (2);
}
