/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:08 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/03 16:57:32 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

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

long	ft_atoi(char *str)
{
	long	ans;
	long	result;

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
	if (!*str)
		exit(1);
	while (*str)
	{
		if (!ft_isdigit(*str))
			exit(1);
		ans = (ans * 10) + (*str - 48);
		str++;
	}
	return (result * ans);
}
