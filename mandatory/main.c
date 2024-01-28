/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:58:41 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 11:58:15 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_char_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        free(arr[i]);
    }
    free(arr);
}

void free_parsing_result(char **par, char *tmp)
{
    free_char_array(par);
    free(tmp);
}

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
	free(tmp);
	return nbrs;
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	char **par;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
    par = parsing(ac, av);
	ft_check_errors(par);
	a = init_stack_a(ft_strlen_array(par), par);
	free_char_array(par);
	if (!is_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
	}
	free_stack(a);
	return (0);
}
