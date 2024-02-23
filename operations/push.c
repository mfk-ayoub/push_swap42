/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 06:23:22 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/22 23:35:27 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_to_pop;

	if (!*src)
		return ;
	push_to_pop = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_to_pop->prev = NULL;
	if (!*dst)
	{
		*dst = push_to_pop;
		(*dst)->next = NULL;
		return ;
	}
	push_to_pop->next = *dst;
	(*dst)->prev = push_to_pop;
	*dst = push_to_pop;
}

void	pa(t_stack **a, t_stack **b, int num)
{
	if (*b != NULL)
	{
		push(a, b);
		if (num == 1)
			ft_putendl_fd("pa", 1);
	}
}

void	pb(t_stack **b, t_stack **a, int num)
{
	if (*a != NULL)
	{
		push(b, a);
		if (num == 1)
			ft_putendl_fd("pb", 1);
	}
}
