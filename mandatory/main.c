/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:58:41 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 08:47:05 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int ft_strlen_array(char **arr)
{
	int length;
	
	length = 0;
	while (arr[length] != NULL)
	{
		length++;
	}
	return (length);
}

char **parsing(int ac, char **av)
{
	int i;
	char **nbrs;
	char *tmp;
	
	i = 1;
	tmp = NULL;
	if (ac == 2)
	{
		nbrs = ft_split(av[1], ' ');
	}
	else
	{
		while (i < ac)
		{
			tmp = ft_strjoin(tmp, av[i]);
			if (i < ac - 1)
				tmp = ft_strjoin(tmp, " ");
			i++;
		}
		nbrs = ft_split(tmp, ' ');
	}

	return nbrs;
}

int main(int ac, char **av)
{
	t_stack *a;
	char **par;

	if (ac < 2)
		return 0;

	par = parsing(ac, av);
	ft_check_errors(par);

	a = init_stack_a(ft_strlen_array(par), par);
	print_stack(a);
	
	bubble_sort_stack(a);
	print_stack(a);

	return 0;
}
