/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:58:41 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/03/02 00:40:50 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fun(char **av)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	while (av[i])
	{
		j = 0;
		flag = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				flag = 1;
			j++;
		}
		i++;
		if (flag == 0)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
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

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**par;

	a = NULL;
	b = NULL;
	fun(av);
	par = parsing(ac, av);
	if (ft_check_errors(par))
	{
		ft_putendl_fd("Error", 2);
		free_char_array(par);
		exit(1);
	}
	a = init_stack(ft_strlen_array(par), par);
	free_char_array(par);
	if (!is_sorted(a))
	{
		big_sort(&a, &b);
	}
	free_stack(a);
	free_stack(b);
	return (0);
}
