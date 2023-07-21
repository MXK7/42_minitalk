/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 07:20:39 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/21 11:08:33 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			j = j * -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * j);
}

static size_t	ft_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	long int		len;
	char			*alpha;

	len = ft_len(n);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	alpha = malloc(sizeof(char) * len + 1);
	if (!alpha)
		return (NULL);
	if (n == 0)
		alpha[0] = '0';
	alpha[len] = '\0';
	len--;
	while (nbr)
	{
		alpha[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		alpha[0] = '-';
	return (alpha);
}
