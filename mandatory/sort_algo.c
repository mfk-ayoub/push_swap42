/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:17:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/03 16:46:33 by ayel-mou         ###   ########.fr       */
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
void small_sort(t_stack **a, t_stack **b)
{
    t_stack *min;

    while (stack_size(*a) > 3)
    {
        min = check_min(*a);
		if (*a == min)
        {
            if ((*a)->next == min)
                sa(a);
            pb(b, a);
        }
        else
        {
            while (*a != min)
                ra(a);
            pb(b, a);
        }
    }
    sort_three(a);
    while (*b != NULL)
        pa(a, b);
}
