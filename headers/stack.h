/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 07:22:28 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/25 21:19:05 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				*elements;
	int				size;
	int				index;
	int				top_index;
	struct s_stack	*prev;
	int				order;
	int				content;
}t_stack;

t_stack		*create_stack(int argc, char **argv);
t_stack		*get_bottom(t_stack *stack);
t_stack		*get_before_bottom(t_stack *stack);
void		add_stack_bottom(t_stack **stack, t_stack *new_node);
void		destroy_stack(t_stack *stack);

t_stack		*push(t_stack **stack, t_stack *new_node);
int			index_stack(t_stack *stack, int num);
int			ft_ps_lstsize(t_stack *lst);

t_stack		*pop(t_stack **stack);
int			peek(t_stack *stack);
int			is_empty(t_stack *stack);
int			is_full(t_stack *stack);
t_stack		*new_node(int content);
void		ft_lstclear_ps(t_stack **lst, void (*deleted)(int));
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);

void		add_stack_elements(t_stack **stack, char **argv);
void		clear_stacks(t_stack **stack_a, t_stack **stack_b);
int			calculate_rotations(t_stack *stack, int value, char stack_name);
void		sort_with_quicksort(t_stack **stack_a);
int			get_last_value(t_stack *stack);
int			sort_minimum(t_stack **stack_a, t_stack **stack_b);
void		move_b2_a(t_stack **stack_a, t_stack **stack_b);
int			get_largest_element(t_stack *stack);
int			chunk_size(int size);
void		move_a2_b(t_stack **a, t_stack **b, int n);
int			*stack_to_array(t_stack *a);
int			*bubble_sort(t_stack *a);
int			place_in_stack(t_stack **a, int v);
void		indexing(t_stack *a);
void		stack_divider(t_stack **a, t_stack **b);

#endif