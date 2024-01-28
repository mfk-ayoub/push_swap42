/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 08:30:26 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 08:36:27 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"


size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	j;

	if (!dest && dstsize == 0)
		return (ft_strlen(src));
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = len_dest;
	if (dstsize <= len_dest)
	{
		return (dstsize + len_src);
	}
	j = 0;
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_dest + len_src);
}