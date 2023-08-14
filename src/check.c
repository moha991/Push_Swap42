/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:46:43 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/31 19:30:28 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	is_valid_number(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != '\0')
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '+' || argv[i][j] == '-')
			{
				if ((argv[i][j + 1] == '+' || argv[i][j + 1] == '-')
				&& !ft_isdigit(argv[i][j]))
					exit_error("Error\n");
				if (!ft_isdigit(argv[i][j + 1]))
					exit_error("Error\n");
				if (argv[i][j + 1] == '+' || argv[i][j + 1] == '-')
					exit_error("Error\n");
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicates(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

void	check_letters(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isalpha(argv[i][j]))
				exit_error("Error\n");
				j++;
		}
	i++;
	}
}

void	verify_input(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
		exit_error("");
	if (argv)
		i++;
	else
		i++;
	return ;
}

/* int	check_range(t_st)
{
while (str[a] >= '0' && str[a] <= '9')
		b = (b * 10) + (str[a++] - '0');
	if (b > 2147483647 && !sign)
		return (-1);
	else if (b > 2147483648 && sign)
		return (0);
	else if (sign)
} */
