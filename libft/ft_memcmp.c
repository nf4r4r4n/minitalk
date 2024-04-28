/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:31:24 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/26 15:35:49 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, t_size_t n)
{
	t_size_t	i;

	if (n == 0 || (!s1 && !s2))
		return (0);
	i = 0;
	while (i < n)
	{
		if (*(t_uchar *)(s1 + i) != *(t_uchar *)(s2 + i))
			return (*(t_uchar *)(s1 + i) - *(t_uchar *)(s2 + i));
		i++;
	}
	return (0);
}
