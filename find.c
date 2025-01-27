/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:27:06 by jmehmy            #+#    #+#             */
/*   Updated: 2025/01/27 20:34:31 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_list **a)
{
	t_list		*count;
	long long	min;

	min = 2147483648;
	count = *a;
	if (count == NULL)
		return (-1);
	if (count->next == NULL)
		return (count->index);
	while (count != NULL)
	{
		if (count->index < min)
			min = count->index;
		count = count->next;
	}
	return (min);
}

int	find_next_min(t_list **a, long long min)
{
	t_list		*count;
	long long	next_min;

	next_min = 2147483648;
	count = *a;
	if (count == NULL || count->next == NULL)
		return (-1);
	while (count != NULL)
	{
		if (count->index < next_min && count->index > min)
			next_min = count->index;
		count = count->next;
	}
	return (next_min);
}

t_list	*find_min_list(t_list **a, long long min)
{
	t_list		*count;
	t_list		*min_list;
	long long	next_min;

	next_min = 2147483648;
	min_list = NULL;
	count = *a;
	while (count != NULL)
	{
		if (count->data < next_min && count->data > min)
		{
			next_min = count->data;
			min_list = count;
		}
		count = count->next;
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
