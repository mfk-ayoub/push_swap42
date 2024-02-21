/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:19:20 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/21 21:43:07 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct u_stack
{
	int				data;
	struct u_stack	*prev;
	struct u_stack	*next;
}					t_stack;

typedef struct helper
{
	int				chunk_size;
	int				mid;
	int				start;
	int				end;
	int				size_array;

}					t_helper;

// helper
size_t				ft_strlen(const char *str);
long long			ft_atoi(char *str);
void				ft_check_errors(char **data);
int					ft_isdigit(int index);
void				ft_putstr_fd(char *str, int fd);
char				**ft_split(char const *s, char c);
char				**parsing(int ac, char **av);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
void				ft_putendl_fd(char *s, int fd);
void				*ft_memcpy(void *to, const void *from, size_t n);
char				*ft_strdup(const char *src);

// swap
void				swap(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
// rotate
void				ra(t_stack **a);
void				rotate(t_stack **stack);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
// push
void				pb(t_stack **b, t_stack **a);
void				pa(t_stack **a, t_stack **b);
void				push(t_stack **dst, t_stack **src);

// reverse rotate
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// free
void				free_stack_node(t_stack *node);
void				free_stack(t_stack *stack);
void				free_char_array(char **arr);

// sorted algo
void				sort_three(t_stack **a);
void				ft_sort_int_tab(int *tab, int size);
int					*array_dup(t_stack *s);
int					size_chunk(t_stack **a);
void				sort_try(t_stack **a, t_stack **b, int *sorted_array);
int					get_numbre_chunk(t_stack **a);
void				big_sort(t_stack **a, t_stack **b);
int					find_numbre_in_stack(t_stack *stack, int num);
void				check_op_b(t_stack **b, int n);
void				last_checking(t_stack **a, t_stack **b, int *tab,
						t_helper *helper);

// checker
int					is_sorted(t_stack *stack);
t_stack				*check_min(t_stack *stack);
t_stack				*check_max(t_stack *stack);
void				fun(char **av, int ac);
// init stack

int					stack_size(t_stack *stack_a);
t_stack				*init_node(int value);
t_stack				*init_stack(int len, char **av);
int					stack_size(t_stack *stack_a);

#endif