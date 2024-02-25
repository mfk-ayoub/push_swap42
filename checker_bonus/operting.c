/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:47:46 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/25 20:02:36 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	compare_1(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp(op, "pb\n"))
		pb(b, a, 0);
	else if (!ft_strcmp(op, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(b, 0);
	else
	{
		ft_putendl_fd("Error", 2);
		free(op);
		free_stack(*a);
		free_stack(*b);
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
	else
		compare_1(a, b, op);
}

void	read_op(t_stack **a, t_stack **b)
{
	char	*rop;

	rop = get_next_line(0);
	while (rop != NULL)
	{
		compare(a, b, rop);
		free(rop);
		rop = get_next_line(0);
	}
}
