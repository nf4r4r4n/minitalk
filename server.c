/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:28:59 by nfararan          #+#    #+#             */
/*   Updated: 2024/04/28 16:54:19 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * We need to set the length of the calculated bits to intercept each
 * character received by the sender every FLAG-bit.
 */
int	g_blen = FLAG;

/**
 * This function will handle signals, especially USR1 and USR2.
 * The signal USR1 will interpret that the transmission has sent 0 as a bit
 * and the signal USR2 will be interpreted as the bit 1.
 * FLAG is the number of bits for ASCII encoding.
 * The algorithm here is simple:
 *  - first we have to do |(OR) operator to our character variable when
 *  signal USR2 is received so that we put the bit 1 to its place
 *  - then we have to shift left (SHL or <<) to this previous variable
 *  so that it can make place for the next bit
 *  - and repeat that until g_blen reaches the FLAG to write the
 *  character to the output.
 */
static void	receive(int sig)
{
	static char	c;

	if (g_blen == FLAG)
		c = 0;
	if (sig == SIGUSR2)
		c |= 1;
	if (g_blen > 1)
		c <<= 1;
	g_blen--;
	if (g_blen == 0)
	{
		ft_putchar_fd(c, 1);
		g_blen = FLAG;
	}
}

int	main(void)
{
	int	pid;

	pid = (int)getpid();
	ft_putstr_fd("[SERVER PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("]\n\n", 1);
	signal(SIGUSR1, receive);
	signal(SIGUSR2, receive);
	while (1)
		pause();
}
