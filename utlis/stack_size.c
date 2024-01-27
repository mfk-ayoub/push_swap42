/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:41:24 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/22 23:17:54 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	stack_size(t_stack  *stack_a)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = stack_a;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}