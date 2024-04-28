/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:12:52 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/26 13:19:43 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, t_size_t n)
{
	t_size_t	i;

	if (dest == FT_NULL && src == FT_NULL)
		return (FT_NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = *(const char *)(src + i);
		i++;
	}
	return (dest);
}
