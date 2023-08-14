/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:04:45 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/24 18:46:34 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_bottom(*stack);
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_putstr("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_putstr("rb\n");
}

void	rr(t_stack **stack)
{
	rotate(stack);
	rotate(stack);
	ft_putstr("rr\n");
}
