/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:05:04 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/28 14:25:24 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	ft_trim_for(const char *s, const char *set, int *i)
{
	while (s[*i] && ft_strchr(set, s[*i]) != FT_NULL)
		*i += 1;
}

static void	ft_trim_back(const char *s, const char *set, int *i)
{
	while (*i > 0 && ft_strchr(set, s[*i]) != FT_NULL)
		*i -= 1;
}

/*
 * The size of the malloc if + 2 because j stop at the character before
 * the waited character to stop and the last is for the '\0'
 */
char	*ft_strtrim(char const *s, char const *set)
{
	int			i;
	int			j;
	char		*t;
	t_size_t	total_size;

	if (!s[0] || !set[0])
		return (ft_strdup(s));
	i = 0;
	ft_trim_for(s, set, &i);
	j = ft_strlen(s) - 1;
	ft_trim_back(s, set, &j);
	if (i <= j)
		total_size = ft_strlen(s) - (i + ft_strlen(s + j)) + 2;
	else
		total_size = 1;
	t = (char *)malloc(total_size * sizeof(char));
	if (!t)
		return (FT_NULL);
	ft_strlcpy(t, s + i, total_size);
	return (t);
}
