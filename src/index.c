/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:57:14 by mfornah           #+#    #+#             */
/*   Updated: 2023/07/25 23:21:41 by mfornah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	*stack_to_array(t_stack *a)
{
	int	i;
	int	len;
	int	*nums;

	i = 0;
	len = ft_lstsize_ps(a);
	nums = malloc(sizeof(int) * len);
	while (a)
	{
		nums[i] = a->value;
		i++;
		a = a->next;
	}
	return (nums);
}

int	*bubble_sort(t_stack *a)
{
	int	len;
	int	*nums;
	int	i;
	int	j;
	int	tmp;

	len = ft_lstsize_ps(a);
	nums = stack_to_array(a);
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (nums[i] > nums[j])
			{
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (nums);
}

void	indexing(t_stack *a)
{
	int	*nums;
	int	i;
	int	len;

	nums = bubble_sort(a);
	len = ft_lstsize_ps(a);
	while (a)
	{
		i = 0;
		while (i < len)
		{
			if (a->value == nums[i])
				a->index = i;
			i++;
		}
		a = a->next;
	}
	free(nums);
}

int	place_in_stack(t_stack **a, int v)
{
	int		index;
	t_stack	*tmp;

	index = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->value == v)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}
