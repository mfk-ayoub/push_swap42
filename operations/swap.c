/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:57:47 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 11:17:23 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		second = (*stack)->next;
		first->next = second->next;
		second->prev = first->prev;
		first->prev = second;
		second->next = first;
		*stack = second;
	}
}
void	sa(t_stack **a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}
void	sb(t_stack **b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}