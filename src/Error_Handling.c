/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_Handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:56:08 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/27 18:17:46 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_full(t_stack *stack)
{
	return (stack->top_index == stack->size - 1);
}

int	is_empty(t_stack *stack)
{
	if (stack->top_index == -1)
		return (1);
	else
		return (0);
}

void	check_malloc(void *ptr)
{
	if (!ptr)
	{
		exit_error("Error: Fallo en la asignación de memoria.\n");
	}
}

void	check_stack_empty(t_stack *stack)
{
	if (is_empty(stack))
		exit(EXIT_FAILURE);
}

void	check_stack_overflow(t_stack *stack)
{
	if (is_full(stack))
	{
		ft_putstr("Error: La pila ha alcanzado su capacidad máxima.\n");
		exit(EXIT_FAILURE);
	}
}
