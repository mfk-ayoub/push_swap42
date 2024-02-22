/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:19:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/22 02:53:18 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_char_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_strlen_array(char **arr)
{
	int	length;

	length = 0;
	while (arr[length] != NULL)
	{
		length++;
	}
	return (length);
}

char	**parsing(int ac, char **av)
{
	char	**nbrs;
	int		i;
	char	*str;
	char	*tmp;

	str = NULL;
	i = 1;
	while (i < ac)
	{
		tmp = ft_strjoin(str, av[i]);
		if (!tmp)
			exit(1);
		free(str);
		str = ft_strjoin(tmp, " ");
		if (!tmp)
			exit(1);
		free(tmp);
		i++;
	}
	nbrs = ft_split(str, ' ');
	free(str);
	if (!nbrs)
		exit(0);
	return (nbrs);
}

void	check_op(t_stack **a,t_stack **b , char	*op)
{
	char	*oper;

	oper = "sa\nsb\nss\npa\npb\nra\nrb\nrr\nrra\nrrb\nrrr\n";
	while (!ft_strnstr(oper,op,ft_strlen(oper)))
	{
		free(a);
		free(b);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	compare(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp(op,"sa"))
		sa(a);
	else if (!ft_strcmp(op,"sb"))
		sb(b);
	else if (!ft_strcmp(op,"ss"))
		ss(a, b);
	else if (!ft_strcmp(op,"ra"))
		ra(a);
	else if (!ft_strcmp(op,"rra"))
		rra(a);
	else if (!ft_strcmp(op,"rrr"))
		rrr(a,b);
	else if (!ft_strcmp(op,"rr"))
		rr(a,b);
	else if (!ft_strcmp(op,"pa"))
		pa(a,b);
	else if (!ft_strcmp(op,"pb"))
		pb(b,a);
	else if (!ft_strcmp(op,"rb"))
		rb(b);
	else if (!ft_strcmp(op,"rrb"))
		rrb(b);
}

void	read_op(t_stack **a,t_stack **b)
{
	char	*rop;

	while ((rop = get_next_line(0)) != NULL)
	{
		compare(a,b,rop);
		check_op(a,b, rop);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**par;

	a = NULL;
	b = NULL;
	par = parsing(ac, av);
	ft_check_errors(par);
	a = init_stack(ft_strlen_array(par), par);
	free_char_array(par);
	read_op(&a,&b);
	if (is_sorted(a))
		ft_putstr_fd("ok\n", 2);
	else if (!is_sorted(a))
		ft_putstr_fd("ko\n", 2);
	return (0);
}

