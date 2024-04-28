/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:04:23 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/23 16:04:40 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, t_size_t len)
{
	t_size_t	i;
	t_size_t	ltlen;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	ltlen = ft_strlen(little);
	while (big[i] && i < len && i + ltlen - 1 < len)
	{
		if (ft_strncmp(big + i, little, ltlen) == 0)
			return ((char *)big + i);
		i++;
	}
	return (FT_NULL);
}
