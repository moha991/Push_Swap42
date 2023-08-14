/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:00:13 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/29 13:24:17 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	find_min(t_stack *stack)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			index = i;
		}
		i++;
		stack = stack->next;
	}
	return (index);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_stack	*current;

	max = INT_MIN;
	current = stack;
	if (!stack)
		return (0);
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

t_stack	*get_before_bottom(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (NULL);
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
