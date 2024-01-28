/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:19:20 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/01/28 11:31:05 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

typedef struct u_stack
{
    int data;
    struct u_stack *prev;
    struct u_stack *next;
}   t_stack;


size_t	ft_strlen(const char *str);
long     ft_atoi(char *str);
void    ft_check_errors(char **data);
int	    ft_isdigit(int index);
void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *s, char c);
char    **parsing(int ac, char **av);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
void	ft_putendl_fd(char *s, int fd);

void print_stack(t_stack *stack_a);
void bubble_sort_stack(t_stack *stack);

// op

void swap(t_stack **stack);
void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);




int is_sorted(t_stack *stack);
int     check_min(t_stack *stack_a);
int     check_max(t_stack *stack_a);
int	    stack_size(t_stack  *stack_a);
t_stack *init_stack_a(int len, char **av);

int	stack_size(t_stack  *stack_a);

#endif 