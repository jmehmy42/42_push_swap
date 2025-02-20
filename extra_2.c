/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin < marvin@42.fr >                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:07:50 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 23:13:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	find_repeats(char **str, int need_clean)
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
			{
				if (need_clean)
					free_string(str);
				ft_perror();
			}
			j++;
		}
		i++;
	}
}

int	check_sort(t_list **a)
{
	t_list	*current_num;

	current_num = *a;
	while (current_num->next != NULL)
	{
		if (current_num->data > current_num->next->data)
			return (0);
		current_num = current_num->next;
	}
	return (1);
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

int	big_number(long index, t_list *number)
{
	t_list	*second;
	t_list	*third;
	int		count;

	count = 0;
	second = number->next;
	third = second->next;
	if (number->index < index)
		count++;
	if (second->index < index)
		count++;
	if (third->index < index)
		count++;
	if (count >= 2)
		return (1);
	return (0);
}
