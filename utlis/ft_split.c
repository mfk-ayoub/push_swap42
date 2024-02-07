/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:48:36 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/06 22:53:25 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

static size_t	ft_count_word(char const *str, char sep)
{
	size_t	index;
	size_t	count_word;

	index = 0;
	count_word = 0;
	while (str[index] == sep && str[index] != '\0')
		index++;
	while (str[index] != '\0')
	{
		while (str[index] != sep && str[index] != '\0')
			index++;
		count_word++;
		while (str[index] == sep && str[index] != '\0')
			index++;
	}
	return (count_word);
}

static size_t	ft_free_memory(char **ptr, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < pos)
		free(ptr[i++]);
	free(ptr);
	return (1);
}

static int	ft_copy2(char **ptr, char const *s1, size_t len, size_t index)
{
	size_t	i;

	i = 0;
	if (len > 0)
	{
		ptr[index] = malloc(len + 1);
		if (ptr[index] == NULL)
		{
			ft_free_memory(ptr, index);
			return (1);
		}
		while (i < len)
		{
			ptr[index][i] = s1[i];
			++i;
		}
		ptr[index][len] = '\0';
	}
	return (0);
}

static size_t	ft_copy(char **ptr, char const *s1, char sep)
{
	size_t	len;
	size_t	index;

	index = 0;
	while (*s1)
	{
		len = 0;
		while (*s1 == sep && *s1)
			++s1;
		while (*s1 != sep && *s1)
		{
			++s1;
			++len;
		}
		if (ft_copy2(ptr, s1 - len, len, index) != 0)
		{
			return (1);
		}
		++index;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = ft_count_word(s, c);
	str = (char **)malloc((words + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	if (ft_copy(str, s, c))
	{
		free(str);
		return (NULL);
	}
	str[words] = NULL;
	return (str);
}
