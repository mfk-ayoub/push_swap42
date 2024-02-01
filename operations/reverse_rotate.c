/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:34:50 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/01 11:43:22 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	reverse_rotate(t_stack** stack)
{
	t_stack* first;
	t_stack* last;

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

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}
void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}
void	rrr(t_stack **a , t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}