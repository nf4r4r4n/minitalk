/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:26:09 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/26 14:54:06 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, t_size_t n)
{
	t_size_t	i;

	if (!dest && !src)
		return (FT_NULL);
	i = 0;
	if (dest <= src)
	{
		while (i < n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	else if (dest > src)
	{
		while (i < n)
		{
			*(char *)(dest + n - i - 1) = *(char *)(src + n - i - 1);
			i++;
		}
	}
	return (dest);
}
