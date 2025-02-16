/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:54:13 by jmehmy            #+#    #+#             */
/*   Updated: 2025/02/16 08:20:02 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *str, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == delimiter)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != delimiter)
			i++;
	}
	return (count);
}

static int	find_next_word(const char *str, char delimiter, int *start,
		int *end)
{
	*start = *end;
	while (str[*start] != '\0' && str[*start] == delimiter)
		(*start)++;
	*end = *start;
	while (str[*end] != '\0' && str[*end] != delimiter)
		(*end)++;
	return (*start < *end);
}

static void	copy_words(char *tab_word, const char *str, int start, int end)
{
	while (start < end)
		*tab_word++ = str[start++];
	*tab_word = '\0';
}

static int	ft_allocate(char **tab, const char *s, char c)
{
	int	word;
	int	start;
	int	end;
	int	i;

	word = 0;
	start = 0;
	end = 0;
	while (find_next_word(s, c, &start, &end))
	{
		tab[word] = malloc((end - start + 1) * sizeof(char));
		if (tab[word] == NULL)
		{
			i = 0;
			while (i < word)
				free(tab[i++]);
			free(tab);
			return (0);
		}
		copy_words(tab[word], s, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	int		size;
	char	**new_s;

	if (s == NULL)
		return (NULL);
	size = count_words(s, c);
	if (size == 0)
		ft_perror();
	new_s = malloc((size + 1) * sizeof(char *));
	if (new_s == NULL)
		return (NULL);
	if (!ft_allocate(new_s, s, c))
	{
		free_string(new_s);
		return (NULL);
	}
	return (new_s);
}
