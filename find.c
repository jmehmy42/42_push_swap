/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:27:06 by jmehmy            #+#    #+#             */
/*   Updated: 2025/02/01 15:25:40 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_small_index(t_list **a)
{
	t_list		*current_num;
	long long	small_index;

	small_index = 2147483648;
	current_num = *a;
	if (!current_num)
		return (-1);
	while (current_num != NULL)
	{
		if (current_num->index < small_index)
			small_index = current_num->index;
		current_num = current_num->next;
	}
	return (small_index);
}

int	find_next_small_index(t_list **a, long long min)
{
	t_list		*current_num;
	long long	next_min;

	next_min = 2147483648;
	current_num = *a;
	if (current_num == NULL || current_num->next == NULL)
		return (-1);
	while (current_num != NULL)
	{
		if (current_num->index < next_min && current_num->index > min)
			next_min = current_num->index;
		current_num = current_num->next;
	}
	return (next_min);
}

t_list	*find_smallest_value(t_list **a, long long min)
{
	t_list		*current_num;
	t_list		*min_list;
	long long	next_value;

	next_value = 2147483648;
	min_list = NULL;
	current_num = *a;
	while (current_num != NULL)
	{
		if (current_num->data < next_value && current_num->data > min)
		{
			next_value = current_num->data;
			min_list = current_num;
		}
		current_num = current_num->next;
	}
	return (min_list);
}

int	find_distance(t_list **a, int c)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *a;
	while (head)
	{
		if (head->index == c)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

int	find_bits(t_list **a)
{
	t_list	*head;
	int		max;
	int		i;

	head = *a;
	max = head->index;
	i = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while (max >> i != 0)
		i++;
	return (i);
}
