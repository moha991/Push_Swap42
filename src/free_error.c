/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:42:03 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/31 21:38:20 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "../headers/push_swap.h"

void	exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit (EXIT_FAILURE);
}

void	deleted(int value)
{
	(void)value;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->value = 0;
		free(*stack);
		*stack = tmp;
	}
}

void	free_matrix(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i]);
		i++;
	}
	free (c);
}

void	clear_stacks(t_stack **stack_a, t_stack **stack_b)
{
	ft_lstclear_ps(stack_a, deleted);
	ft_lstclear_ps(stack_b, deleted);
}
