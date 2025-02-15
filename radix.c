/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:04:13 by jmehmy            #+#    #+#             */
/*   Updated: 2025/02/15 11:13:09 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_list **a, t_list **b)
{
	int		size;
	int		bits;
	int		i;
	int		j;

	size = ft_lstsize(a);
	bits = find_bits(a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (ft_lstsize(b) != 0)
			pa(a, b);
		i++;
	}
}
