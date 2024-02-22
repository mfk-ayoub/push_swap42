/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:19:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/22 06:36:22 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	fun(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}

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
		free(tmp);
		if (!str)
			exit(1);
		i++;
	}
	nbrs = ft_split(str, ' ');
	free(str); 
	if (!nbrs)
		exit(0);
	return (nbrs);
}


void check_op(t_stack **a, t_stack **b, char *op)
{
    char *oper;

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
	if (!ft_strcmp(op,"sa\n"))
		sa(a);
	else if (!ft_strcmp(op,"sb\n"))
		sb(b);
	else if (!ft_strcmp(op,"ss\n"))
		ss(a, b);
	else if (!ft_strcmp(op,"ra\n"))
		ra(a);
	else if (!ft_strcmp(op,"rra\n"))
		rra(a);
	else if (!ft_strcmp(op,"rrr\n"))
		rrr(a,b);
	else if (!ft_strcmp(op,"rr\n"))
		rr(a,b);
	else if (!ft_strcmp(op,"pa\n"))
		pa(a,b);
	else if (!ft_strcmp(op,"pb\n"))
		pb(b,a);
	else if (!ft_strcmp(op,"rb\n"))
		rb(b);
	else if (!ft_strcmp(op,"rrb\n"))
		rrb(b);
}

void	read_op(t_stack **a,t_stack **b)
{
	char	*rop;

	while ((rop = get_next_line(0)) != NULL)
	{
		check_op(a,b, rop);
		compare(a,b,rop);
		free(rop);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**par;

	a = NULL;
	b = NULL;
	fun(av, ac);
	par = parsing(ac, av);
	ft_check_errors(par);
	a = init_stack(ft_strlen_array(par), par);
	free_char_array(par);
	read_op(&a,&b);
	if (is_sorted(a))
		ft_putstr_fd("ok\n", 2);
	else
		ft_putstr_fd("ko\n", 2);
	free_stack(a);
	free_stack(b);
	return (0);
}


