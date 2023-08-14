/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:55:22 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/25 23:23:56 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "../headers/push_swap.h"

int	get_largest_element(t_stack *stack)
{
	int	max;

	max = INT_MIN;
	while (stack != NULL)
	{
		if (stack-> value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	chunk_size(int size)
{
	int	chunk;

	chunk = 1;
	if (size < 50)
		chunk = 3 + (size - 6) / 7;
	else if (size >= 50 && size < 100)
		chunk = 10 + (size - 50) / 8;
	else if (size >= 100 && size < 350)
		chunk = 15;
	else if (size >= 350 && size <= 500)
		chunk = 27 + (size - 350) / 15;
	else if (size > 500)
		chunk = 37 + (size - 500) / 20;
	return (chunk);
}

void	move_b2_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max;

	while (*stack_b)
	{
		size = ft_lstsize_ps(*stack_b);
		max = place_in_stack(stack_b, get_largest_element(*stack_b));
		if (max <= (size - 1) / 2)
		{
			max = get_largest_element(*stack_b);
			while ((*stack_b)->value != max)
				rb(stack_b);
		}
		else
		{
			max = get_largest_element(*stack_b);
			while ((*stack_b)->value != max)
				rrb(stack_b);
		}
		pa(stack_b, stack_a);
	}
}

void	move_a2_b(t_stack **a, t_stack **b, int n)
{
	int	counter;

	counter = 0;
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			pb(a, b);
			rb(b);
			counter++;
		}
		else if ((*a)->index <= counter + n)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}
}

void	stack_divider(t_stack **a, t_stack **b)
{
	int	size;
	int	n;

	size = ft_lstsize_ps(*a);
	n = chunk_size(size);
	move_a2_b(a, b, n);
	move_b2_a(a, b);
}
