/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emiro-co <emiro-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:24:29 by emiro-co          #+#    #+#             */
/*   Updated: 2023/06/22 18:33:12 by emiro-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "printf/ft_printf.h"

char	translate(const char *s)
{
	int	d;
	int	m;
	int	i;

	i = 7;
	d = 0;
	m = 1;
	while (i >= 0)
	{
		d += (s[i] - '0') * m;
		m *= 2;
		i--;
	}
	return ((char)d);
}

void	recived(int signum)
{
	static char	s[8];
	static int	i;

	if (signum == SIGUSR1)
	{
		s[i] = '0';
		i++;
	}
	else if (signum == SIGUSR2)
	{
		s[i] = '1';
		i++;
	}
	if (i == 8)
	{
		ft_printf("%c", translate(s));
		i = 0;
	}
}

int	main(void)
{
	int	pid;
	int	i;

	i = 0;
	pid = getpid();
	ft_printf("Num de proceso: %d\n", pid);
	while (i != -1)
	{
		signal(SIGUSR1, recived);
		signal(SIGUSR2, recived);
		pause();
		i++;
	}
	return (0);
}
