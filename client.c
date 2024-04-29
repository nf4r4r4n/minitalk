/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 09:33:38 by nfararan          #+#    #+#             */
/*   Updated: 2024/04/29 10:58:35 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * This function will send a character <c> to the process id <pid>.
 * The character is interpret as a suit of bits especilly 8 bits (1 byte)
 * and it's the appropriate number of bits for the ASCII character encoding.
 * The way that we send bit by bit the character is simple:
 * 	- create an integer mask to get each bit (mask = 0b10000000)
 * 	- do the bitwise operator &(AND) between the character and the mask
 * 	- do the bitwise operator >>(SHR: shift right) once to the mask
 * 	- iterate the operations bellow until byte flag is null (byte flag is
 * 	the number of bits, 8 for ASCII)
 */
static void	ft_send_char(int pid, int c)
{
	int	mask;
	int	byte_flag;

	mask = 0b10000000;
	byte_flag = 8;
	while (byte_flag)
	{
		if (c & mask)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		byte_flag--;
		mask >>= 1;
	}
}

/**
 * This function role is to send each character of "str"
 * to the specified process id (pid).
 */
static void	ft_send_str(int pid, const char *str)
{
	while (*str)
	{
		ft_send_char(pid, *str);
		str++;
	}
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

	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("\33[1;31mError on usage\n\33[0m", 1);
		ft_putstr_fd("\33[1;31mTry ./client <pid> <message>\n\33[0m", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("\33[1;31mInvalid PID\n\33[0m", 1);
		return (1);
	}
	msg = argv[2];
	ft_send_str(pid, ">>> ");
	ft_send_str(pid, msg);
	ft_send_str(pid, "\n");
	ft_send_char(pid, 0);
}
