/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:08 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/21 23:43:01 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	check_overflow(unsigned long long num)
{
	if (num > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
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
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	check_overflow(ans);
	return (result * ans);
}
