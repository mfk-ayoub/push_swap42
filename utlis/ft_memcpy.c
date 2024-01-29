/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 03:28:26 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/29 03:28:31 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

void	*ft_memcpy(void *to, const void *from, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*str;

	if (to == NULL && from == NULL)
		return (NULL);
	ptr = to;
	str = (unsigned char *)from;
	if (ptr == str)
	{
		return (ptr);
	}
	i = 0;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	return (ptr);
}