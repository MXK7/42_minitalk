/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:20:45 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/21 11:11:03 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		send_bit(pid, (c >> i) & 1);
		i++;
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char *argv[])
{
	char	*message;
	int		pid_server;

	if (argc != 3)
	{
		printf("Usage: %s <PID du serveur> <message>\n", argv[0]);
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	message = argv[2];
	printf("%d\n%s", pid_server, message);
	send_message(pid_server, message);
	return (0);
}
