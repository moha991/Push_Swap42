/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:49:49 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/30 18:10:35 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_stack	*new_node(int content)
{
	t_stack		*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit_error("Error: fallo en la asignación de memoria\n");
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*get_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	add_stack_bottom(t_stack **stack, t_stack *node_new)
{
	t_stack	*bottom;

	if (!stack || !node_new)
		return ;
	if (!*stack)
		*stack = node_new;
	else
	{
		bottom = get_bottom(*stack);
		bottom->next = node_new;
	}
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*stack;
	char	**tmp;
	int		i;
	int		x;

	i = 1;
	stack = NULL;
	while ((i < argc))
	{
		if (argv[i][0] == '\0')
			exit(1);
		tmp = ft_split(argv[i], 32);
		if (!tmp)
			exit_error("Error\n");
		x = 0;
		add_stack_elements(&stack, tmp);
		free_matrix(tmp);
		i++;
	}
	return (stack);
}

void	add_stack_elements(t_stack **stack, char **argv)
{
	int	x;
	int	j;

	x = 0;
	while (argv[x])
	{
		j = ft_atoi_push_swap(argv[x]);
		add_stack_bottom(stack, new_node(j));
		x++;
	}
}
