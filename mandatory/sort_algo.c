/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:17:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/16 04:26:26 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort_three(t_stack **a)
{
    t_stack *max;

    max = check_max(*a);
    if (*a == max)
    {
        ra(a);
    }
    else if ((*a)->next == max)
    {
        rra(a);
    }
    if ((*a)->data > (*a)->next->data)
    {
        sa(a);
    }
}

int		find_number(t_stack **a, int number)
{
	t_stack *tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->data == number)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

void	check_a_push(t_stack **a, t_stack **b, int *arr, int start, int end)
{
	int i = start;
	while (i <= end)
	{
		if (find_number(a, arr[i]))
		{
			pb(b, a);
			if (stack_size(*b) > 1 && (*b)->data < (*b)->next->data)
				rb(b);
		}
		else
		{
			ra(a);
			i++;
		}
	}
}

void sort_try(t_stack **a, t_stack **b)
{
    int *array;
    int i;
    int temp;
    int chunk;

    array = array_dup(*a);
    ft_sort_int_tab(array, stack_size(*a));
    i = 0;
    chunk = stack_size(*a) / size_chunk(a);
    temp = chunk;
    while (i < stack_size(*a))
    {
        check_a_push(a, b, array,i ,i + chunk);
        
		i += chunk;
    }
    free(array);
}

