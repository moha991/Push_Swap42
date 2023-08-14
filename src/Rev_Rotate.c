/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rev_Rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:49:35 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/24 18:36:49 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*penultimate;
	t_stack	*tmp;

	tail = get_bottom(*stack);
	penultimate = get_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	penultimate->next = NULL;
}

void	rra(t_stack **a)
{
	reverse(a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **b)
{
	reverse(b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	ft_putstr("rrr\n");
}
