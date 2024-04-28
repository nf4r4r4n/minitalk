/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:12:28 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/27 13:22:37 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dup;
	const t_size_t	slen = ft_strlen(s);
	t_size_t		i;

	if (s == 0)
		dup = (char *)ft_calloc(1, sizeof(char));
	else
		dup = (char *)ft_calloc(slen + 1, sizeof(char));
	if (!dup)
		return (FT_NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
