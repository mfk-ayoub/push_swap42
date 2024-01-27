/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_av.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 05:30:55 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/23 05:31:40 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

char **string_to_av(char *av, int *ac)
{
	int	i;
	char	**ret;
	i = 0;
	*ac = 0;
	ret = ft_split(av, ' ');
	while (ret[*ac])
		(*ac)++;
	i = *ac;
	while (i)
	{
		ret[i] = ret[i - 1];
		i--;
	}
	(*ac)++;
	return (ret);
}