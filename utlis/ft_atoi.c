/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:08 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/23 03:35:31 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	check_overflow(unsigned long long num)
{
	if (num > INT_MAX)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_isdigit(int index)
{
	if ('0' <= index && '9' >= index)
		return (1);
	return (0);
}

static bool	is_space(char c)
{
	char	*str;

	str = "\t\n\v\f\r ";
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

long long	ft_atoi(char *str)
{
	long long	ans;
	long long	result;

	ans = 0;
	result = 1;
	if (str == NULL)
		return (0);
	while (is_space(*str))
		str++;
	if (*str == '-')
		result *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		ans = (ans * 10) + (*str - '0');
		str++;
	}
	if (check_overflow(ans))
	{
	}
	return (result * ans);
}

void	check_ove(char **data)
{
	unsigned long int	i;
	long long			value;

	i = 0;
	while (data[i])
	{
		value = ft_atoi(data[i]);
		if (check_overflow(value))
		{
			free_char_array(data);
			exit(1);
		}
		i++;
	}
}
