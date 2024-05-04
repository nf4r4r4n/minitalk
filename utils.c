/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:50:01 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/04 21:54:48 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_server_info(int pid)
{
	ft_putstr_fd("[SERVER PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("]\n\n>>> ", 1);
}

void	ft_handle_errors(int argc, char **argv)
{
	int	i;
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_putstr_fd("\33[1;31mError on usage\n\33[0m", 1);
		ft_putstr_fd("\33[1;31mTry ./client <pid> <message>\n\33[0m", 1);
		exit(1);
	}
	i = 0;
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			exit(1);
}

/**
 * This function role is to send each character of "str"
 * to the specified process id (pid).
 */
void	ft_send_str(int pid, const char *str)
{
	while (*str)
		ft_send_char(pid, *str++);
}

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
void	ft_send_char(int pid, int c)
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

void	ft_exit_failure(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(1);
}
