/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:59:23 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/31 21:33:00 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "error_handling.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "../libft/srcs/libft.h"

# define INT_MIN -2147483647

# define INT_MAX 2147483647

# define LONG_MAX 9223372036854775807 

# define LONG_MIN -9223372036854775807 

int		ft_atol(char *str);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort_two(t_stack **a);
void	sort_three(t_stack **stack);
void	sort_five(t_stack **a, t_stack **b);
void	sort_four(t_stack **a, t_stack **b);
void	sort_large(t_stack *a, t_stack *b, int size);
void	sorting(t_stack **a, t_stack **b);

int		find_min(t_stack *stack);
int		find_max(t_stack *stack);

int		is_sorted(t_stack *stack);
void	swap(t_stack **a);
void	rotate(t_stack **stack);
void	reverse(t_stack **stack);

int		ft_atoi_push_swap( char *str);
int		ft_lstsize_ps(t_stack *lst);
void	small_sort(int length, t_stack **a, t_stack **b);
int		main(int argc, char **argv);
void	quicksort(int *c, int start, int end);
t_stack	*sort_stack_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*sort_stack_b(t_stack **stack_b);
t_stack	*find_pivot(t_stack *stack);
void	print_stack(t_stack *stack);

int		partition(int *c, int start, int end);

#endif
