/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:20:41 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/21 11:36:49 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

static void	message_send(char *message)
{
	int	i;

	ft_putstr(message);
	i = 0;
	while (i < MESSAGE_SIZE)
	{
		message[i] = '\0';
		i++;
	}
}

void	receive_bit(int sig)
{
	static t_server_data	server;

	if (sig == SIGUSR1)
		server.received_message[server.current_char]
			|= (0 << server.current_bit);
	else if (sig == SIGUSR2)
		server.received_message[server.current_char]
			|= (1 << server.current_bit);
	server.current_bit++;
	if (server.current_bit >= 8)
	{
		server.current_bit = 0;
		server.current_char++;
		if (server.received_message[server.current_char - 1] == '\0')
		{
			server.current_char = 0;
			message_send(server.received_message);
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = receive_bit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr(ft_itoa(getpid()));
	while (1)
		sleep(1);
	return (0);
}
