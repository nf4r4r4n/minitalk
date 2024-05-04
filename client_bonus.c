/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:57:42 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/04 22:05:53 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_msg_received(int sig)
{
	if (sig == SIGUSR1)
		ft_putendl_fd("Message received", 1);
}

/**
 * Let's make sure that we must use 2 arguments for the present program.
 * The 1st argument (argv[1]) will be the process id (pid) of the receiver.
 * The 2nd argument (argv[2]) will be the message that the sender will
 * transmit to the receiver.
 */
int	main(int argc, char **argv)
{
	int			pid;
	char		*msg;

	ft_handle_errors(argc, argv);
	if (signal(SIGUSR1, ft_msg_received) == SIG_ERR)
		ft_exit_failure("\33[1;31mUSR1: Error while receiving signal\33[0m");
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	ft_send_str(pid, msg);
	ft_send_char(pid, 0);
}
