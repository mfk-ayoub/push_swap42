/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:59:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/03 16:46:38 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    big_sort(t_stack **a,t_stack **b)
{
    if (stack_size(*a) <= 10)
        small_sort(a,b);
}
