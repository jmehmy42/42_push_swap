/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:43:36 by jmehmy            #+#    #+#             */
/*   Updated: 2025/02/15 11:24:17 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	t_list	*head;

	head = *a;
	if (big_number(head->data, head))
		ra(a);
	else if (big_number(head->next->data, head))
		rra(a);
	head = *a;
	if (head->data > head->next->data)
		sa(a);
}

void	sort_4(t_list **a, t_list **b)
{
	int	distance;

	if (check_sort(a))
		return ;
	distance = find_distance(a, find_small_index(a));
	if (distance == 1 || distance == 2)
	{
		ra(a);
		if (distance == 2)
			ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (check_sort(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_list **a, t_list **b)
{
	int	distance;

	distance = find_distance(a, find_small_index(a));
	if (distance == 1 || distance == 2)
	{
		ra(a);
		if (distance == 2)
			ra(a);
	}
	else if (distance == 3 || distance == 4)
	{
		rra(a);
		if (distance == 3)
			rra(a);
	}
	if (check_sort(a))
		return ;
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	handle_sorting(t_list **a, t_list **b, int count)
{
	t_list	*head;

	head = *a;
	if (check_sort(a))
		return ;
	if (count == 2)
	{
		if (head->index > head->next->index)
			sa(a);
	}
	else if (count == 3)
		sort_3(a);
	else if (count == 4)
		sort_4(a, b);
	else if (count == 5)
		sort_5(a, b);
	else if (count > 5)
		radix(a, b);
}
