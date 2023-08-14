/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:27:10 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/29 13:27:57 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_stack **stack)
{
	int	max;

	max = find_max(*stack);
	if (is_sorted(*stack))
		return ;
	if ((*stack)->value == max)
		ra(stack);
	else if ((*stack)->next->value == max)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = find_min(*a);
	if (min == 1)
		sa(a);
	else if (min == 2)
	{
		rra(a);
		rra(a);
	}
	else if (min == 3)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sort_three(a);
	pa(b, a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	smallest;

	smallest = find_min(*a);
	if (smallest == 1)
		sa(a);
	if (smallest == 2)
	{
		ra(a);
		ra(a);
	}
	if (smallest == 3)
	{
		rra(a);
		rra(a);
	}
	if (smallest == 4)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sort_four(a, b);
	pa(b, a);
}
