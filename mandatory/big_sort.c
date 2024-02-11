/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:59:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/11 05:21:28 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **a, t_stack **b)
{


	if (!is_sorted(*a))
	{

		while (stack_size(*a))
		{
				try(a, b);
		}
	}
	while (b)
	{
			if ((*b)->data == check_max(*b)->data)
				pa(a, b);
			else 
				rb(b);
	}
}

// void try(t_stack **a, t_stack **b)
// {
// 	int *array = array_dup(*a);
// 	ft_sort_int_tab(array, stack_size(*a));
// 	t_stack *tmp;
// 	t_stack *node;
// 	int len = stack_size(*a);
// 	int flag = 0;
	
// 	tmp = *a;
// 	while (tmp)
// 	{
// 		if (stack_size(*a) > len / 2)
// 		{
// 			node = tmp->next;
// 			int i = 0;
// 			while (i <= len / 2)
// 			{
// 				if (tmp->data == array[i])
// 					flag = 1;
// 				i++;
// 			}
// 			if (flag == 1)
// 			{
// 				pb(b,a);
// 				flag = 0;
// 			}
// 			else
// 				ra(a);
// 			tmp = node;
// 		}
// 		else
// 			break ;
// 	}
// 	  free(array);
//  }
 void try(t_stack **a, t_stack **b) {
    // Check if stack a is NULL or empty
    if (!a || !(*a))
        return;

    int *array = array_dup(*a);
    if (!array)
        return; // Allocation failed, handle appropriately

    ft_sort_int_tab(array, stack_size(*a));
    t_stack *tmp = *a;
    int len = stack_size(*a);
    int flag = 0;

    while (tmp) {
        if (stack_size(*a) > len / 2) {
            t_stack *node = tmp->next;
            int i = 0;
            while (i <= len / 2) {
                if (tmp->data == array[i]) {
                    flag = 1;
                    break; // No need to continue searching
                }
                i++;
            }
            if (flag == 1) {
                pb(b, a);
                flag = 0;
            } else {
                ra(a);
            }
            tmp = node;
        } else {
            break;
        }
    }

    // Free dynamically allocated memory
    free(array);
}
