/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:27:06 by jmehmy            #+#    #+#             */
/*   Updated: 2025/01/30 18:03:06 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **a)
{
	t_list		*current;
	long long	min;

	min = 2147483648;
	current = *a;
	if (current == NULL)
		return (-1);
	if (current->next == NULL)
		return (current->index);
	while (current != NULL)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

int	find_next_min(t_list **a, long long min)
{
	t_list		*current;
	long long	next_min;

	next_min = 2147483648;
	current = *a;
	if (current == NULL || current->next == NULL)
		return (-1);
	while (current != NULL)
	{
		if (current->index < next_min && current->index > min)
			next_min = current->index;
		current = current->next;
	}
	return (next_min);
}

t_list	*find_smallest_value(t_list **a, long long min)
{
	t_list		*current;
	t_list		*min_list;
	long long	next_value;

	next_value = 2147483648;
	min_list = NULL;
	current = *a;
	while (current != NULL)
	{
		if (current->data < next_value && current->data > min)
		{
			next_value = current->data;
			min_list = current;
		}
		current = current->next;
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
