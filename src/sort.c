/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:37:12 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/31 20:03:04 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "../headers/push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sorting(t_stack **a, t_stack **b)
{
	int	length;

	length = ft_lstsize_ps(*a);
	if (length <= 5)
	{
		small_sort(length, a, b);
		ft_lstclear_ps(a, deleted);
		ft_lstclear_ps(b, deleted);
	}
	else if (length > 5)
	{
		indexing(*a);
		stack_divider(a, b);
		ft_lstclear_ps(a, deleted);
		ft_lstclear_ps(b, deleted);
	}
}

void	small_sort(int length, t_stack **a, t_stack **b)
{
	if (length == 2)
		sort_two(a);
	else if (length == 3)
		sort_three(a);
	else if (length == 4)
		sort_four(a, b);
	else if (length == 5)
		sort_five(a, b);
}

int	get_last_value(t_stack *stack)
{
	if (stack == NULL)
		return (-1);
	while (stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack->value);
}
