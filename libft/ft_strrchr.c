/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:56:26 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/23 10:09:15 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*occur;
	t_size_t	i;

	occur = FT_NULL;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
			occur = (char *)s + i;
		i++;
	}
	if (*(s + i) == (char)c)
		occur = (char *)s + i;
	return (occur);
}
