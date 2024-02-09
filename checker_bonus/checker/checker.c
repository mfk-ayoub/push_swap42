/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:19:06 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/09 22:20:34 by ayel-mou         ###   ########.fr       */
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
	nbrs = ft_split(str,' ');
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
	par = parsing(ac, av);
	ft_check_errors(par);
	a = init_stack(ft_strlen_array(par), par);
	free_char_array(par);
	return (0);
}