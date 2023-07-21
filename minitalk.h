/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:28:04 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/21 08:25:01 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define MESSAGE_SIZE 1024

typedef struct s_server_data
{
	char	received_message[MESSAGE_SIZE];
	int		current_bit;
	int		current_char;
	int		message_complete;
}			t_server_data;

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);

void		send_message(int pid, char *message);
void		receive_message(int sig);
void		receive_bit(int sig);

#endif