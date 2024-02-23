/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:34:50 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/22 23:35:35 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack = last;
	}
}

void	rra(t_stack **a, int num)
{
	reverse_rotate(a);
	if (num == 1)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **b, int num)
{
	reverse_rotate(b);
	if (num == 1)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **a, t_stack **b, int num)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (num == 1)
		ft_putendl_fd("rrr", 1);
}
