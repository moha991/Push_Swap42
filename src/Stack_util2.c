/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:56:36 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/30 10:35:47 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_stack	*push(t_stack **stack, t_stack *new_node)
{
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else
	{
		new_node->next = *stack;
		new_node->prev = NULL;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
	return (new_node);
}

void	destroy_stack(t_stack *stack)
{
	free (stack->elements);
	free (stack);
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*top;

	top = *stack;
	if (*stack)
		*stack = (*stack)->next;
	return (top);
}

int	ft_ps_lstsize(t_stack *lst)
{
	int		size;
	t_stack	*current;

	size = 0;
	current = lst;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}
