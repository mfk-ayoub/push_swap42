/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:17:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/19 12:16:17 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *head, int wanted)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->index == wanted)
			return (i);
		i++;
		head = head->next;
	}
	return (-1);
}
void cheking_and_push(t_stack **a, t_stack **b)
{
    while (*b)
    {
        while ((*b)->index != stack_size(*b) - 1)
            if (get_index(*b, stack_size(*b) - 1) <= stack_size(*b) / 2)
                rb(b);
            else
                rrb(b);
    }
    pa(a, b);
}


void free_all(int *tab, t_helper *helper)
{
    if (tab != NULL)
        free(tab);
    if (helper != NULL)
        free(helper);
}

void	checking_operat(t_stack **a, t_helper	*helper, int *tab)
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

void sort_helper(t_stack **a, int *tab, t_helper *helper)
{
    t_stack *check_range = *a;

    while (check_range && !(check_range->data >= tab[helper->start]
                            && check_range->data <= tab[helper->end]))
        check_range = check_range->next;
    
    if (!check_range)
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

void sort_try(t_stack **a, t_stack **b, int *sorted_array)
{   
    t_helper     *helper;
    int          chunk_length;
   
    helper = (t_helper *)malloc(sizeof(t_helper));
    chunk_length = get_numbre_chunk(a);
    helper->chunk_size = chunk_length;
    helper->mid = stack_size(*a) / 2;
    helper->start = helper->mid - chunk_length;
    helper->end = helper->mid + chunk_length;
    helper->size_array = stack_size(*a);
    while (*a)
    {
        if ((*a)->data >= sorted_array[helper->start] && (*a)->data <= sorted_array[helper->end])
        {
            pb(b, a);
            if ((*b) && (*b)->data < sorted_array[helper->mid])
                rb(b);
        }
        else
            sort_helper(a, sorted_array, helper);
    }
    cheking_and_push(a,b);
   free_all(sorted_array,helper);
}









