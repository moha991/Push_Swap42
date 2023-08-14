/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 20:09:09 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/31 21:31:29 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*stack_b;

	stack_b = NULL;
	stack = create_stack(argc, argv);
	verify_input(argc, argv);
	if (argc > 1)
	{
		if (check_duplicates(stack))
			exit_error("Error\n");
		check_letters(argv);
		ft_atoi_push_swap(*argv);
		is_valid_number(argv);
		if (is_sorted(stack))
		{
			clear_stacks(&stack, &stack_b);
			return (0);
		}
		else if (!is_sorted(stack))
			sorting(&stack, &stack_b);
	}
	return (0);
}
