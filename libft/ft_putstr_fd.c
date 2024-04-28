/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:52:22 by nfararan          #+#    #+#             */
/*   Updated: 2024/02/29 15:54:24 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int		i;
	const unsigned int	len = ft_strlen(s);

	i = 0;
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
