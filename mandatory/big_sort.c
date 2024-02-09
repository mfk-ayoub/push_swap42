/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:59:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/07 03:39:14 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{

	if (stack_size(*a) <= 5)
		small_sort(a, b);
	else
		simple_sort(a,b);
}

void	simple_sort(t_stack **a, t_stack **b)
{
	t_stack		*min_stack;
	t_stack		*max_stack;
	
	while (a && (*a)->next != NULL)
	{
		max_stack = check_max(*a);
		min_stack = check_min(*a);
		if (*a == min_stack)
			pb(a,b);
		else if (min_stack->data <= stack_size(*a) / 2)
		{
			ra(a);
			pb(a,b);
		}	
		else{
			rra(a);
			pb(a,b);
		}
	}
	while (*b)
	{
		pa(a, b);
	}
}


































































// void	ft_sort_four(t_stack *a, t_stack *stack_b)
// {
// 	int	min;

// 	if (check_sort(a))
// 		return ;
// 	min = find_min(a);
// 	while (a->tab[0] != min && a->tab[a->len - 1] != min)
// 		ra(a);
// 	if (a->tab[a->len - 1] == min)
// 		rra(a);
// 	if (check_sort(a))
// 		return ;
// 	pb(a, stack_b);
// 	ft_sort_three(a);
// 	pa(a, stack_b);
// }

// void	ft_sort_five(t_stack *a, t_stack **b)
// {
// 	int	min;

// 	min = find_min(a);
// 	while (a->tab[0] != min && a->tab[a->len - 1] != min && a->tab[a->len
// 			- 2] != min)
// 		ra(a);
// 	if (a->tab[a->len - 1] == min)
// 		rra(a);
// 	else if (a->tab[a->len - 2] == min)
// 	{
// 		rra(a);
// 		rra(a);
// 	}
// 	if (check_sort(a))
// 		return ;
// 	pb(a, stack_b);
// 	ft_sort_four(a, stack_b);
// 	pa(a, stack_b);
// }