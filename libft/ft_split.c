/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:01:54 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/05 12:10:32 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_size_t	count_words(char const *s, char c)
{
	t_size_t	words;
	t_size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (i > 0 && s[i - 1] == c && s[i] != c)
				words++;
			else if (i == 0 && s[i] != c)
				words++;
			i++;
		}
	}
	return (words);
}

static void	free_array(char **arr, t_size_t size)
{
	t_size_t	i;

	i = 0;
	while (i < size)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
}

static void	check_word(char const *s, char c, t_size_t *i, t_size_t *j)
{
	while (s[*i] && s[*i] == c)
		*i += 1;
	*j = *i;
	while (s[*i] && s[*i] != c)
		*i += 1;
}

char	**ft_split(char const *s, char c)
{
	t_size_t	i;
	t_size_t	j;
	t_size_t	k;
	char		**arr;

	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (FT_NULL);
	i = 0;
	j = 0;
	k = 0;
	while (k < count_words(s, c))
	{
		check_word(s, c, &i, &j);
		arr[k] = ft_substr(s, j, i - j);
		if (!arr[k])
		{
			free_array(arr, k);
			return (FT_NULL);
		}
		k++;
	}
	arr[k] = FT_NULL;
	return (arr);
}
