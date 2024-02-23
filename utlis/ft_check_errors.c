/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:39:13 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/22 23:57:20 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	ft_all_isdigit(char **data)
{
	int	i;
	int	j;

	i = 0;
	while (data[i])
	{
		j = 0;
		if (data[i][0] == '-' || data[i][0] == '+')
		{
			if (!data[i][1])
				return (0);
			else
				j++;
		}
		while (data[i][j])
		{
			if (!ft_isdigit(data[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_duplicate(char *str1, char *str2)
{
	int	num1;
	int	num2;

	num1 = ft_atoi(str1);
	num2 = ft_atoi(str2);
	if (num1 == num2)
	{
		return (1);
	}
	return (0);
}

int	ft_duplicate(char **data)
{
	int	i;
	int	j;

	i = 0;
	while (data[i] != NULL)
	{
		j = i + 1;
		while (data[j] != NULL)
		{
			if (is_duplicate(data[i], data[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_size(char **data)
{
	unsigned long int	i;
	long int			value;

	i = 0;
	while (data[i])
	{
		value = ft_atoi(data[i]);
		if (!(value >= INT_MIN && value <= INT_MAX))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_errors(char **data)
{
	if (!ft_all_isdigit(data))
	{
		return (1);
	}
	if (ft_duplicate(data))
	{
		return (1);
	}
	if (ft_size(data))
	{
		return (1);
	}
	else
		return (0);
}
