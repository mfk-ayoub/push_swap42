/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:17:38 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/01 11:50:44 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **a)
{
    t_stack *max = check_max(*a);

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