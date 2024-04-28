/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:20:59 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/27 14:29:32 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip_char(const char *nptr, t_size_t *i)
{
	while (nptr[*i] && ft_strchr("\t\v\n\r\f ", nptr[*i]) != FT_NULL)
		*i += 1;
}

int	ft_atoi(const char *nptr)
{
	t_size_t	i;
	int			sign;
	int			result;

	i = 0;
	sign = 1;
	result = 0;
	ft_skip_char(nptr, &i);
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		result = result * 10 + ((t_uchar)nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
