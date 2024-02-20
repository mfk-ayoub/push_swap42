/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:33:43 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/20 20:08:42 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;

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

void	big_sort(t_stack **a, t_stack **b)
{
	int	*sorted_array;

	sorted_array = array_dup(*a);
	ft_sort_int_tab(sorted_array, stack_size(*a));
	if (stack_size(*a) == 2)
		sa(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else
		sort_try(a, b, sorted_array);
}
