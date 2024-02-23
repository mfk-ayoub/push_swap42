/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:57:50 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/22 23:35:46 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = first;
		first->prev = last;
		*stack = first->next;
		first->next = NULL;
		(*stack)->prev = NULL;
	}
}

void	ra(t_stack **a, int num)
{
	rotate(a);
	if (num == 1)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack **b, int num)
{
	rotate(b);
	if (num == 1)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b, int num)
{
	ra(a, num);
	rb(b, num);
	if (num == 1)
		ft_putendl_fd("rr", 1);
}
