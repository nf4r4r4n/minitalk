/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:38:34 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/27 12:39:57 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(t_size_t nmemb, t_size_t size)
{
	t_uchar	*ptr;

	ptr = (t_uchar *)malloc(nmemb * size);
	if (!ptr)
		return (FT_NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
