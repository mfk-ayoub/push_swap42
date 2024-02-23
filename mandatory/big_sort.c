/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:33:43 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/23 15:09:57 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = check_max(*a);
	if (*a == max)
		ra(a, 1);
	else if ((*a)->next == max)
		rra(a, 1);
	if ((*a)->data > (*a)->next->data)
		sa(a, 1);
}

void	sort_4_and_5(t_stack **a, t_stack **b)
{
	t_stack	*min_a;

	while (stack_size(*a) != 3)
	{
		min_a = check_min(*a);
		if (*a == min_a)
			pb(b, a, 1);
		else
			ra(a, 1);
	}
	sort_three(a);
	while (*b)
	{
		pa(a, b, 1);
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	*sorted_array;

	sorted_array = array_dup(*a);
	ft_sort_int_tab(sorted_array, stack_size(*a));
	if (stack_size(*a) == 2)
		sa(a, 1);
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) >= 4 && stack_size(*a) <= 5)
	{
		sort_4_and_5(a, b);
	}
	else
		sort_try(a, b, sorted_array);
	free(sorted_array);
}
