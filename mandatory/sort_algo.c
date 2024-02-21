/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:17:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/21 10:23:54 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(int *tab, t_helper *helper)
{
	if (tab != NULL)
		free(tab);
	if (helper != NULL)
		free(helper);
}

void last_checking(t_stack **a, t_stack **b,int *tab,t_helper *helper)
{

	t_stack	*tmp;

	tmp = *a;
	if (!tmp)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->data == tab[helper->size_array - 1]
		|| tmp->data < (*b)->data)
	{
		pa(a,b);
		ra(a);
	}
}

void	best_move_b(t_stack **b, int n)
{
	t_stack	*tmp;
	int		moves;

	moves = 0;
	tmp = *b;
	while (tmp)
	{
		if (tmp->data == n)
			break ;
		moves++;
		tmp = tmp->next;
	}
	if (moves == 0)
		return ;
	if (moves <= stack_size(*b) / 2)
		rb(b);
	else
		rrb(b);
}

void revina(t_stack **a,int *tab , int index)
{
	while ((*a)->data != tab[index - 1] && (*a)->data != tab[index])
				rra(a);
}





void	cheking_and_push(t_stack **a, t_stack **b, int *tab,t_helper *helper)
{
	int		index;

	index = stack_size(*b);
	while (*b)
	{
		if ((*b)->data == tab[index])
		{
			pa(a, b);
			index--;
		}
		else if (find_numbre_in_stack(*b, tab[index]))
		{
			revina(a, tab, index);
			index--;
		}
		else
		{
			last_checking(a,b,tab,helper);
			best_move_b(b,tab[index]);
		}
	}
	while ((*a)->data > tab[0])
		rra(a);
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
		ra(a);
	else
		rra(a);
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
			pb(b, a);
			if ((*b) && (*b)->data < sorted_array[helper->mid])
				rb(b);
		}
		else
			sort_helper(a, sorted_array, helper);
	}
	cheking_and_push(a, b, sorted_array,helper);
	free_all(sorted_array, helper);
}
