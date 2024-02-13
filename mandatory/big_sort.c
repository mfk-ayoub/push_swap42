/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:59:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/13 07:09:26 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// void	big_sort(t_stack **a)
// {

// 	sort_try(a);

//     // t_stack *max_stack;
// 	// if (!is_sorted(*a))
// 	// {

// 	// 	while (stack_size(*a))
// 	// 	{
// 	// 			try(a, b);
// 	// 	}
// 	// }
// 	// while (b)
// 	// {   
//     //         max_stack = check_max(*b);
// 	// 		if (*b == max_stack)
// 	// 			pa(a, b);
// 	// 		else if (*b != max_stack)
// 	// 			rb(b);
//     //         else
//     //             break;
// 	// }
// }

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

int		*party_stack(int *array, int size, int start)
{

	int *array_copy;
	int x = 0;
	array_copy = malloc(size * sizeof(int));
	while(start < size)
	{
		array_copy[x] = array[start];
		start++;
		x++;
	}
	return 	 (array_copy);
}
void ft_titsh(t_stack **a, t_stack **b, int *test, int size)
{
    int i;
    t_stack *tmp;
    t_stack *node;
    int flag = 0; // Initialize flag

    tmp = *a;
    while (tmp)
    {
        node = tmp->next;
        i = 0;
        if (stack_size(*a) > size / 2) // Corrected condition check
        {
            while (i <= size / 2)
            {
                if (tmp->data == test[i])
                {
                    flag = 1;
                    break; // Exit loop if match found
                }
                i++;
            }
            if (flag == 1)
            {
                pb(b, a);
                flag = 0;
            }
            else
            {
                ra(a);
            }
        }
        tmp = node; // Move to the next node
    }
}


void  sort_try(t_stack **a, t_stack **b)
{
	int *array = array_dup(*a);
	int size;
	int *x;
	int i;
	int inc; 
	int start = 0;
	b = NULL;
	i = 0;
	ft_sort_int_tab(array, stack_size(*a));
	size = size_array(a);
	inc = stack_size(*a) / size;
	printf ("%d\n\n", stack_size(*a));
	while(start < stack_size(*a))
	{
		x = party_stack(array, inc, start);
		ft_titsh(a,b,x,inc);
		free(x);
		start += stack_size(*a) / size;
		inc += stack_size(*a) / size;
	}
	free(array);
}

