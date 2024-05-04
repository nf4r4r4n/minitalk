/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfararan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:19:41 by nfararan          #+#    #+#             */
/*   Updated: 2024/05/04 22:45:07 by nfararan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

/* Flag is the number of bits for the ascii encoding */
# ifndef FLAG
#  define FLAG 8
# endif

void	ft_server_info(int pid);
void	ft_handle_errors(int argc, char **argv);
void	ft_send_str(int pid, const char *str);
void	ft_send_char(int pid, int c);
void	ft_exit_failure(char *msg);
void	ft_banner(void);

#endif
