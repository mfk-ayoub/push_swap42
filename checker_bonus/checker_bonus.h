/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:19:34 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/29 00:29:46 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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

// get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
void				list_maker(t_list **list, int fd);
void				add_to_list(t_list **list, char *buf);
char				*get_the_line(t_list *list);
void				clist(t_list **list);
void				dealloc(t_list **list, t_list *clean_node, char *buf);
void				copy_the_list(t_list *list, char *the_line);
int					llist(t_list *list);
int					newline_checker(t_list *list);
// helper
size_t				ft_strlen(const char *str);
long long			ft_atoi(char *str);
int					ft_check_errors(char **data);
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
void				sa(t_stack **a, int num);
void				sb(t_stack **b, int num);
void				ss(t_stack **a, t_stack **b, int num);
// rotate
void				ra(t_stack **a, int num);
void				rotate(t_stack **stack);
void				rb(t_stack **b, int num);
void				rr(t_stack **a, t_stack **b, int num);
// push
void				pb(t_stack **b, t_stack **a, int num);
void				pa(t_stack **a, t_stack **b, int num);
void				push(t_stack **dst, t_stack **src);

// reverse rotate
void				reverse_rotate(t_stack **stack);
void				rra(t_stack **a, int num);
void				rrb(t_stack **b, int num);
void				rrr(t_stack **a, t_stack **b, int num);

// free
void				free_stack_node(t_stack *node);
void				free_stack(t_stack *stack);
void				free_char_array(char **arr);

// init stack

int					stack_size(t_stack *stack_a);
t_stack				*init_node(int value);
t_stack				*init_stack(int len, char **av);

char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_strcmp(char *s1, char *s2);
int					is_sorted(t_stack *stack);
void				fun(char **av);
int					check_overflow(unsigned long int num);
void				check_ove(char **data);
void				check_op(t_stack **a, t_stack **b, char *op);
void				compare(t_stack **a, t_stack **b, char *op);
void				read_op(t_stack **a, t_stack **b);

#endif