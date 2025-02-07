/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:07:50 by jmehmy            #+#    #+#             */
/*   Updated: 2025/02/07 19:53:50 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_small_to_top(t_list **a, int min_index)
{
	t_list	*head;

	head = *a;
	if (head->next->index == min_index)
		ra(a);
	else
	{
		sa(a);
		rra(a);
	}
}

void	assign_indexes(t_list **a)
{
	t_list	*head;
	int		i;

	i = 0;
	head = find_smallest_value(a, -2147483649);
	while (head)
	{
		head->index = i;
		head = find_smallest_value(a, head->data);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

void	find_repeats(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				ft_perror();
			j++;
		}
		i++;
	}
}
