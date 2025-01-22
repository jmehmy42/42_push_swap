/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:50:29 by jmehmy            #+#    #+#             */
/*   Updated: 2025/01/21 19:15:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_single_input(t_list **a, char *list)
{
	t_list	*new;
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_split(list, ' ');
	find_repeats(str);
	while (str[i])
	{
		new = ft_lstnew(ft_atoi(str[i]));
		if (!new)
			ft_perror();
		ft_lstadd_back(a, new);
		i++;
	}
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (i);
}

int	process_multiple_inputs(t_list **a, char **list)
{
	t_list	*new;
	int		i;

	i = 1;
	find_repeats(list);
	while (list[i])
	{
		new = ft_lstnew(ft_atoi(list[i]));
		if (!new)
			ft_perror();
		ft_lstadd_back(a, new);
		i++;
	}
	i -= 1;
	return (i);
}

int	check_sort(t_list **a)
{
	t_list	*check;

	check = *a;
	while (check->next != NULL)
	{
		if (check->next->data < check->data)
			return (0);
		check = check->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		count;

	if (ac < 2)
		return (-1);

	a = NULL;
	b = NULL;
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
