/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:17:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/16 04:35:35 by ayel-mou         ###   ########.fr       */
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

int		find_number(t_stack **a, int number)
{
    // t_stack *tmp;
	
	// tmp = *a;
    // while (tmp != NULL)
    // {
        if ((*a)->data == number)
            return (1);
    //     tmp = tmp->next;
    // }
    return (0);
}

void	check_a_push(t_stack **a, t_stack **b, int *arr, int max)
{
    int i;

    i = 0;
    while (stack_size(*a) && i < max)
    {
        if (find_number(a, arr[i])) 
        {
			pb(b,a);
        }
        else
        {
            ra(a);
            i++;
        }
    }
		// b = NULL;
		// while (stack_size(*a) && i < max)
		// {
		// 	printf("%d\n",arr[i]);
		// 	i++;
		// }
		// printf("\ntest\n");
}


void	sort_try(t_stack **a, t_stack **b)
{
    int *array;
    int i;
	int temp;
    int chunk;
  
    array = array_dup(*a);
    ft_sort_int_tab(array, stack_size(*a));
    i = 1;
    chunk = stack_size(*a) /size_chunk(a);
	temp = chunk;
    while (i < size_chunk(a) + 1)
    {
        check_a_push(a, b, array, chunk);
		
		chunk += temp;
        i++;
    }
    free(array);
}

