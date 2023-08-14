/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:04:52 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/24 18:47:21 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	swap(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_putstr("ss\n");
}
