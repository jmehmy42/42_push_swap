/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:09:32 by jmehmy            #+#    #+#             */
/*   Updated: 2025/02/18 23:08:02 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '0' && str[i + 2] == '\0')
			return (false);
		if (str[i + 1] == '\0')
			return (false);
		i++;
	}
	if (str[0] == '+')
		return (false);
	if (str[i] == '0' && str[i + 1] != '\0')
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

void	exit_invalid_number(char *str, t_list **a, char **str2)
{
	if (!is_valid_number(str))
	{
		if (str2)
			free_string(str2);
		ft_perror2(a);
	}
}

void	check_overflow(long num, t_list **a, char **str2)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		if (str2)
			free_string(str2);
		ft_perror2(a);
	}
}

int	ft_atoi(char *str, t_list **a, char **str2)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	exit_invalid_number(str, a, str2);
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	check_overflow(num * sign, a, str2);
	return ((num * sign));
}
