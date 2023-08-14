/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:49:07 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/24 16:49:06 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	push_2stack(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)-> next;
	(*src)-> next = *dest;
	*dest = *src;
	*src = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push_2stack(a, b);
	ft_putstr("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push_2stack(a, b);
	ft_putstr("pb\n");
}
