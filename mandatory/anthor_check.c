/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anthor_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:41:31 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/21 11:42:32 by ayel-mou         ###   ########.fr       */
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
		rb(b);
	else
		rrb(b);
}

void	last_checking(t_stack **a, t_stack **b, int *tab, t_helper *helper)
{
	t_stack	*tmp;

	tmp = *a;
	if (!tmp)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->data == tab[helper->size_array - 1] || tmp->data < (*b)->data)
	{
		pa(a, b);
		ra(a);
	}
}

void	revina(t_stack **a, int *tab, int index)
{
	while ((*a)->data != tab[index - 1] && (*a)->data != tab[index])
		rra(a);
}
