/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:59:14 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 08:37:27 by ayel-mou         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size != 0)
	{
		while (src[len] != '\0' && len < size - 1)
		{
			dst[len] = src[len];
			len++;
		}
		dst[len] = '\0';
	}
	return (ft_strlen(src));
}
char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(len * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len);
	ft_strlcat(res, s2, len);
	return (res);
}