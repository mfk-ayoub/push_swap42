/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthor_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:41:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/29 00:35:15 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_op_b(t_stack **b, int n)
{
	t_stack	*tmp;
	int		op;

	op = 0;
	tmp = *b;
	while (tmp)
	{
		if (tmp->data == n)
			break ;
		op++;
		tmp = tmp->next;
	}
	if (op == 0)
		return ;
	if (op <= stack_size(*b) / 2)
		rb(b, 1);
	else
		rrb(b, 1);
}

int	last_checking(t_stack **a, t_stack **b, int *tab, t_helper *helper)
{
	t_stack	*tmp;

	tmp = *a;
	if (!tmp)
		return (0);
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->data == tab[helper->size_array - 1] || tmp->data < (*b)->data)
	{
		pa(a, b, 1);
		ra(a, 1);
		return (1);
	}
	return (0);
}
