/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:11:52 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/22 10:33:29 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size_t	ft_strlcpy(char *dst, const char *src, t_size_t size)
{
	t_size_t	i;
	t_size_t	srclen;

	srclen = ft_strlen(src);
	if (size <= 0)
		return (srclen);
	i = 0;
	while (i < (size - 1) && *(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (srclen);
}
