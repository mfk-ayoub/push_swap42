/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utlis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 06:13:47 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/23 03:01:11 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	newline_checker(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

int	llist(t_list *list)
{
	int	i;
	int	l;

	l = 0;
	while (list)
	{
		i = 0;
		if (list == NULL)
			return (0);
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				l++;
				return (l);
			}
			i++;
			l++;
		}
		list = list->next;
	}
	return (l);
}

void	copy_the_list(t_list *list, char *the_line)
{
	int	i;
	int	j;

	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i] != '\0')
		{
			if (list->content[i] == '\n')
			{
				the_line[j] = '\n';
				the_line[++j] = '\0';
				return ;
			}
			the_line[j++] = list->content[i++];
		}
		list = list->next;
	}
	the_line[j] = '\0';
}

void	dealloc(t_list **list, t_list *clean_node, char *buf)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->content[0])
		*list = clean_node;
	else
	{
		free(buf);
		free(clean_node);
	}
}
