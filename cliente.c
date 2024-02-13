/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:32:41 by yugao             #+#    #+#             */
/*   Updated: 2024/02/09 21:14:55 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_kill(pid_t pid, int sig)
{
	if (kill (pid, sig) == -1)
	{
		ft_putstr_fd ("Error cuando se intenta enviar la informacion! \n", 1);
		exit (EXIT_FAILURE);
	}
}

static void	send_msg(pid_t pid, char *msg)
{
	unsigned char	c;
	int				bit_num;

	while (*msg)
	{
		c = *msg;
		bit_num = 8;
		while (bit_num --)
		{
			if (c & 0b10000000)
				ft_kill (pid, SIGUSR1);
			else
				ft_kill (pid, SIGUSR2);
			usleep (100);
			c <<= 1;
		}
		msg ++;
	}
}

int	main(int arc, char **arg)
{
	pid_t	pid;

	if (arc <= 2 || arc >= 4)
	{
		ft_putstr_fd ("No ha introducido los argumentos correctos !\n", 1);
		return (1);
	}
	pid = ft_atoi (arg[1]);
	if (pid <= 0)
	{
		ft_putstr_fd ("No ha sido extraido PID con exito !\n", 1);
		return (1);
	}
	send_msg (pid, arg[2]);
	return (0);
}
