/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:42:28 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/31 21:33:45 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_atoi_push_swap(char *str)
{
	long	number;

	number = ft_atol(str);
	if (number < INT_MIN || number > INT_MAX)
		exit_error("Error\n");
	return (number);
}

int	ft_lstsize_ps(t_stack *lst)
{
	int	size;

	size = 0;
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			size++;
		}
		return (size + 1);
	}
	return (0);
}

void	ft_lstclear_ps(t_stack **lst, void (*deleted)(int))
{
	t_stack	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		deleted((*lst)->value);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	if (new && lst)
	{
		new -> next = *lst;
		*lst = new;
	}
}

int	ft_atol(char *str)
{
	long	a;
	long	b;
	long	sign;

	a = 0;
	b = 0;
	sign = 0;
	while (str[a] == '\t' || str[a] == '\r' || str[a] == ' ' || str[a] == '\n')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a++] == '-')
			sign++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		b = (b * 10) + (str[a++] - '0');
		if ((b > LONG_MAX && !sign) || (b > -(LONG_MIN + 1) && sign))
			exit_error("Error\n");
	}
	if (sign)
		b *= -1;
	if (b > INT_MAX || b < INT_MIN)
		exit_error("Error\n");
	return ((int)b);
}
