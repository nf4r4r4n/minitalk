/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:44:21 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/27 12:48:15 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size_t	ft_strlcat(char *dst, const char *src, t_size_t size)
{
	t_size_t		i;
	const t_size_t	dlen = ft_strlen(dst);
	const t_size_t	slen = ft_strlen(src);

	if (size <= dlen)
		return (size + slen);
	i = 0;
	while (i < size - dlen - 1 && src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
