/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:33:43 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/21 13:09:58 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = check_max(*a);
	if (*a == max)
		ra(a);
	else if ((*a)->next == max)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	contuine(t_stack **a, t_stack **b)
{
	t_stack	*max_b;

	while (*b)
	{
		max_b = check_max(*b);
		if (*b == max_b)
			pa(a, b);
		else
			sb(b);
		pa(a, b);
	}
}

void	sort_4_and_5(t_stack **a, t_stack **b)
{
	t_stack	*min_a;

	while (stack_size(*a) != 3)
	{
		min_a = check_min(*a);
		if (*a == min_a)
			pb(b, a);
		else if ((*a)->next == min_a)
		{
			sa(a);
			ra(a);
		}
		else
			rra(a);
	}
	sort_three(a);
	contuine(a, b);
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
	else if (stack_size(*a) >= 4 && stack_size(*a) <= 5)
		sort_4_and_5(a, b);
	else
		sort_try(a, b, sorted_array);
}
