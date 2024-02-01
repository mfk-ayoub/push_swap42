/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 06:23:22 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/01 11:15:20 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"


void	push(t_stack **s, int nb)
{
	t_stack *top;

	top = init_node(nb);

	if (s)
	{
		top->next = *s;
		top->prev = NULL;
		if (*s)
		{
			(*s)->prev = top;
		}
		*s = top;
	}
}
void pa(t_stack **a, t_stack **b)
{
    if (*b != NULL)
    {
        push(a, (*b)->data);
        ft_putendl_fd("pa", 1);
    }
}

void pb(t_stack **b, t_stack **a)
{
    if (*a != NULL)
    {
        push(b, (*a)->data);

        ft_putendl_fd("pb", 1);
    }
}