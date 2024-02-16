/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:17:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/16 02:14:28 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = check_max(*a);
	if (*a == max)
	{
		ra(a);
	}
	else if ((*a)->next == max)
	{
		rra(a);
	}
	if ((*a)->data > (*a)->next->data)
	{
		sa(a);
	}
}


// void sort_try(t_stack **a, t_stack **b)
// {
//     int *array;
//     int i;
//     int chunk_size;
//     int chunk;

//     array = array_dup(*a);
//     ft_sort_int_tab(array, stack_size(*a));
//     chunk_size = size_chunk(a);
//     chunk = stack_size(*a) / chunk_size;
//     i = 1;
//     while(i <= chunk_size + 1)
//     {
        
        
//     }
//     free(array);
// }