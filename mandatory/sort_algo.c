/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:17:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/29 00:34:24 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cheking_and_push(t_stack **a, t_stack **b, int *tab, t_helper *helper)
{
	int	index;

	index = stack_size(*b) - 1;
	while (*b)
	{
		if ((*b)->data == tab[index])
		{
			pa(a, b, 1);
			index--;
		}
		else if (find_numbre_in_stack(*a, tab[index]))
		{
			while ((*a)->data != tab[index - 1] && (*a)->data != tab[index])
				rra(a, 1);
			index--;
		}
		else
		{
			if (!last_checking(a, b, tab, helper))
				check_op_b(b, tab[index]);
		}
	}
	while ((*a)->data > tab[0])
		rra(a, 1);
}

void	checking_operat(t_stack **a, t_helper *helper, int *tab)
{
	t_stack	*tmp;
	int		oper;

	oper = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->data >= tab[helper->start] && tmp->data <= tab[helper->end])
			break ;
		oper++;
		tmp = tmp->next;
	}
	if (oper <= (stack_size(*a) / 2))
		ra(a, 1);
	else
		rra(a, 1);
}

void	sort_helper(t_stack **a, int *tab, t_helper *helper)
{
	t_stack	*range;

	range = *a;
	while (range && !(range->data >= tab[helper->start]
			&& range->data <= tab[helper->end]))
		range = range->next;
	if (!range)
	{
		helper->start -= helper->chunk_size;
		helper->end += helper->chunk_size;
		if (helper->start < 0)
			helper->start = 0;
		if (helper->end > helper->size_array - 1)
			helper->end = helper->size_array - 1;
	}
	else
		checking_operat(a, helper, tab);
}

void	sort_try(t_stack **a, t_stack **b, int *sorted_array)
{
	t_helper	*helper;
	int			chunk_length;

	helper = (t_helper *)malloc(sizeof(t_helper));
	chunk_length = get_numbre_chunk(a);
	helper->chunk_size = chunk_length;
	helper->mid = stack_size(*a) / 2;
	helper->start = helper->mid - chunk_length;
	helper->end = helper->mid + chunk_length;
	helper->size_array = stack_size(*a);
	while (*a)
	{
		if ((*a)->data >= sorted_array[helper->start]
			&& (*a)->data <= sorted_array[helper->end])
		{
			pb(b, a, 1);
			if ((*b) && (*b)->data < sorted_array[helper->mid])
				rb(b, 1);
		}
		else
			sort_helper(a, sorted_array, helper);
	}
	cheking_and_push(a, b, sorted_array, helper);
	free(helper);
}
