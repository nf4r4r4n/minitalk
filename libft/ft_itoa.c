/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 08:55:42 by nfararan          #+#    #+#             */
/*   Updated: 2024/03/01 10:30:27 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_size_t	digits(int n)
{
	t_size_t	d;

	d = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		d++;
		n /= 10;
	}
	return (d);
}

/*
 * The function return the value for 0 at the end
 */
static char	*ft_switch(int n)
{
	if (n == FT_INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == FT_INT_MAX)
		return (ft_strdup("2147483647"));
	return (ft_strdup("0"));
}

static void	itochar(char *s, int n, t_size_t i)
{
	if (n > 9)
	{
		s[i] = n % 10 + '0';
		itochar(s, n / 10, i - 1);
	}
	else
		s[i] = n + '0';
}

char	*ft_itoa(int n)
{
	char		*s;
	t_size_t	d;
	int			tmp;

	if (n == FT_INT_MIN || n == FT_INT_MAX || n == 0)
		return (ft_switch(n));
	d = digits(n);
	tmp = n;
	if (n < 0)
	{
		tmp *= -1;
		d++;
	}
	s = (char *)malloc((d + 1) * sizeof(char));
	if (!s)
		return (FT_NULL);
	itochar(s, tmp, d - 1);
	if (n < 0)
		s[0] = '-';
	s[d] = '\0';
	return (s);
}
