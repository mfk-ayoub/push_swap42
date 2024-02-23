/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:47:46 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/23 03:17:09 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_op(t_stack **a, t_stack **b, char *op)
{
	char	*oper;

	oper = "sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n";
	while (!ft_strnstr(oper, op, ft_strlen(oper)))
	{
		if (*a != NULL)
			free_stack(*a);
		if (*b != NULL)
			free_stack(*b);
		ft_putstr_fd("Error\n", 2);
		free(op);
		exit(1);
	}
}

void	compare(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(op, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(op, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(op, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(op, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(a, b, 0);
	else if (!ft_strcmp(op, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(op, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(op, "pb\n"))
		pb(b, a, 0);
	else if (!ft_strcmp(op, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(b, 0);
}

void	read_op(t_stack **a, t_stack **b)
{
	char	*rop;

	rop = get_next_line(0);
	while (rop != NULL)
	{
		check_op(a, b, rop);
		compare(a, b, rop);
		free(rop);
		rop = get_next_line(0);
	}
}
