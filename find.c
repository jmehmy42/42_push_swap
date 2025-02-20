/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin < marvin@42.fr >                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:27:06 by marvin            #+#    #+#             */
/*   Updated: 2025/02/11 19:17:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_small_index(t_list **a)
{
	t_list		*current;
	long long	small_index;

	small_index = 2147483648;
	current = *a;
	if (!current)
		return (-1);
	while (current != NULL)
	{
		if (current->index < small_index)
			small_index = current->index;
		current = current->next;
	}
	return (small_index);
}

t_list	*find_smallest_value(t_list **a, long long small_number)
{
	t_list		*current;
	t_list		*smallest_node;
	long long	smallest_value;

	smallest_value = 2147483648;
	smallest_node = NULL;
	current = *a;
	while (current != NULL)
	{
		if (current->data < smallest_value && current->data > small_number)
		{
			smallest_value = current->data;
			smallest_node = current;
		}
		current = current->next;
	}
	return (smallest_node);
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
	while (max > 0)
	{
		max = max / 2;
		i++;
	}
	return (i);
}
