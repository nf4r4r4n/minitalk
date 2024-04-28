/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:45:13 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/26 15:09:29 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, t_size_t n)
{
	t_size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(t_uchar *)(s + i) == (t_uchar)c)
			return ((t_uchar *)s + i);
		i++;
	}
	return (FT_NULL);
}
