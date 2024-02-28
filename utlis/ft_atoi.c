/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:08 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/28 01:33:17 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	check_overflow(unsigned long int num)
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
	long long int	ans;
	long long		result;

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
		return (2147483648);
	}
	return (result * ans);
}

void	check_ove(char **data)
{
	unsigned long int	i;

	i = 0;
	while (data[i])
	{
		if (ft_atoi(data[i]) == 2147483648)
		{
			ft_putendl_fd("Error", 2);
			free_char_array(data);
			exit(1);
		}
		i++;
	}
}
