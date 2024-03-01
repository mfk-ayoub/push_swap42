/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:08 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/03/02 00:47:31 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int	check_overflow(unsigned long int num)
{
	if (num > INT_MAX)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	else
		return (0);
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
	long long			ans;
	long long			result;
	unsigned long int	res;

	res = 1;
	ans = 0;
	result = 1;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		result *= -1;
		res = 0;
	}
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		ans = (ans * 10) + (*str - '0');
		str++;
	}
	if (res == 1 && check_overflow(ans))
		exit(1);
	return (result * ans);
}
