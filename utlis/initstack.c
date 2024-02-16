/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayel-mou <ayel-mou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 00:31:28 by ayel-mou          #+#    #+#             */
/*   Updated: 2024/02/16 02:11:57 by ayel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/push_swap.h"

t_stack	*init_node(int value)
{
	t_stack	*stack_node;

	stack_node = malloc(sizeof(t_stack));
	if (stack_node == NULL)
	{
		return (NULL);
	}
	stack_node->data = value;
	stack_node->next = NULL;
	stack_node->prev = NULL;
	return (stack_node);
}

t_stack	*add_stack(t_stack *stack, int value)
{
	t_stack	*tmp;
	t_stack	*new_node;

	tmp = stack;
	new_node = init_node(value);
	if (stack == NULL)
		return (new_node);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
	return (stack);
}

t_stack	*init_stack(int len, char **av)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (i < len)
	{
		stack = add_stack(stack, ft_atoi(av[i]));
		i++;
	}
	if  (stack == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	return (stack);
}

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}
int	stack_size(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next;

	current = stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}