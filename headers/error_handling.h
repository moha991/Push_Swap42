/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 07:22:54 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/27 18:09:47 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "stack.h"

void	verify_input(int argc, char **argv);
void	check_malloc(void *ptr);
void	check_stack_empty(t_stack *stack);
void	check_stack_overflow(t_stack *stack);
void	verify_sort(int argc, char **argv);
void	check_negative_numbers(t_stack *stack);
void	check_letters(char **argv);
int		is_valid_number(char **argv);
int		check_duplicates(t_stack *stack);
void	exit_error(char *msg);
void	free_stack(t_stack **stack);
void	free_matrix(char **c);
void	deleted(int value);
int		index_in_stack(t_stack *stack, int v);
int		check_range(t_stack *stack);

#endif