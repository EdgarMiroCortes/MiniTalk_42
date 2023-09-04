/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:26:37 by emiro-co          #+#    #+#             */
/*   Updated: 2023/06/22 19:41:02 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	i;
	int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

void	translate(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
			usleep(500);
		}
		else
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
			usleep(500);
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	char	*mensaje;
	int		pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		printf("Introduce un PID y el mensaje a enviar");
		return (0);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		mensaje = argv[2];
		while (mensaje[i] != 0)
		{
			translate(pid, mensaje[i]);
			i++;
		}
	}
	return (0);
}
