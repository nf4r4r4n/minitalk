/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:57:16 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/04 22:49:18 by nfararan         ###   ########.fr       */
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
static void	ft_receive(int sig, siginfo_t *info, void *context)
{
	static char	c;

	(void)context;
	if (g_blen == FLAG)
		c = 0;
	if (sig == SIGUSR2)
		c |= 1;
	if (g_blen > 1)
		c <<= 1;
	g_blen--;
	if (g_blen == 0)
	{
		g_blen = FLAG;
		if (c == 0)
		{
			ft_putstr_fd("\n\33[1;34m>>> \33[0m", 1);
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_exit_failure("USR1: Error on reply client");
			usleep(100);
			return ;
		}
		ft_putchar_fd(c, 1);
	}
}

static void	ft_sig_configs(void (*act_hdl)(int, siginfo_t *, void *))
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = act_hdl;
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ft_exit_failure("USR1: Signal config error");
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ft_exit_failure("USR2: Signal config error");
}

int	main(void)
{
	int	pid;

	pid = (int)getpid();
	ft_banner();
	ft_server_info(pid);
	while (1)
		ft_sig_configs(ft_receive);
}
