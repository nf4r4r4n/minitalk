/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:02:17 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/01 14:31:03 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, t_size_t len)
{
	char		*sub;
	t_size_t	i;

	if (start >= ft_strlen(str))
		len = 0;
	else if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (FT_NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = str[i + start];
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
