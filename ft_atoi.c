/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:09:32 by jmehmy            #+#    #+#             */
/*   Updated: 2025/01/30 16:30:42 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_number(long long num, char *str)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if (str[i] > 57 || str[i] < 48)
			ft_perror();
	}
	if (num == INT_MAX || num == INT_MIN)
		return (true);
	else if (num > 2147483647 || num < -2147483648)
		return (false);
	else if ((num == 0 && str[0] != '0') || (str[0] == '0' && str[1] != '\0')
		|| str[0] == '+')
		return (false);
	else
		return (true);
}

int	ft_atoi(char *str)
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
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		num = ((num * 10) + (str[i] - '0'));
		i++;
	}
	if (!is_number(num * sign, str))
		ft_perror();
	return (num * sign);
}
