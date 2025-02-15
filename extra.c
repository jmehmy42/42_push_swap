/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:30:33 by jmehmy            #+#    #+#             */
/*   Updated: 2025/02/10 14:18:20 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int number)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = number;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*str;

	if (!lst)
		return (NULL);
	str = lst;
	while (str->next)
		str = str->next;
	return (str);
}

int	ft_lstsize(t_list **lst)
{
	int		i;
	t_list	*head;

	i = 0;
	head = *lst;
	if (!lst)
		return (0);
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	ft_free(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
