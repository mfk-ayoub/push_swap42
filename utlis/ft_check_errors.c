/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:39:13 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/02 10:34:42 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
int ft_all_isdigit(char **data)
{
    int i;

    i = 0; 
    while (data[i])
    {
        int j = 0;
        if(data[i][0] == '-')
            j++;
        while (data[i][j])
        {
            if (!ft_isdigit(data[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int  ft_duplicate(char **data)
{
    int i;
    int j;

    i = 0;
    while (data[i])
    {
        j = i + 1;
        while (data[j])
        {
            if (ft_strcmp(data[i], data[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
void ft_check_errors(char **data)
{
    int i = 0;

    if (!ft_all_isdigit(data))
    {
        ft_putstr_fd("Error\n", 2);
        free_char_array(data);
        exit(1);     
    }
    if (ft_duplicate(data))
    {
        ft_putstr_fd("Error\n", 2);
        free_char_array(data);
        exit(1);
    }
    while (data[i])
    {
        long value = ft_atoi(data[i]);
        if (!(value >= INT_MIN && value <= INT_MAX))
        {
            ft_putstr_fd("Error\n", 2);
           	free_char_array(data); 
            exit(1);
        }
        i++;
    }
}
