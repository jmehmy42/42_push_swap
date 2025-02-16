/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:34:57 by jmehmy            #+#    #+#             */
/*   Updated: 2025/02/16 23:08:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_single_input(t_list **a, char *list)
{
	t_list	*new;
	char	**str;
	int		i;

	i = 0;
	str = ft_split(list, ' ');
	if (!str)
		return (-1);
	find_repeats_1(str);
	while (str[i])
	{
		new = ft_lstnew(ft_atoi(str[i], a, str));
		if (!new)
		{
			//ft_free(a);
			ft_perror2(a);
		}
		ft_lstadd_back(a, new);
		i++;
	}
	return (i);
}

int	process_multiple_inputs(t_list **a, char **list)
{
	t_list	*new;
	int		i;

	i = 1;
	find_repeats_2(list);
	while (list[i])
	{
		new = ft_lstnew(ft_atoi_2(list[i], a));
		if (!new)
		{
			//ft_free(a);
			ft_perror2(a);
		}
		ft_lstadd_back(a, new);
		i++;
	}
	return (i - 1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		count;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (-1);
	if (ac == 2)
		count = process_single_input(&a, av[1]);
	else
		count = process_multiple_inputs(&a, av);
	assign_indexes(&a);
	handle_sorting(&a, &b, count);
	ft_free(&a);
	ft_free(&b);
	return (0);
}
