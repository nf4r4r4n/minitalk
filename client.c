/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:33:38 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/04 13:11:43 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	pid = ft_atoi(argv[1]);
	msg = argv[2];
	ft_send_str(pid, msg);
	ft_send_char(pid, 0);
}
