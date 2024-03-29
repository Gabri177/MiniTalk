/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:51:07 by yugao             #+#    #+#             */
/*   Updated: 2024/02/09 19:56:45 by yugao            ###   ########.fr       */
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
	int				num_bit;

	while (*msg)
	{
		c = *msg;
		num_bit = 7;
		while (num_bit >= 0)
		{
			if (c & (1 << num_bit))
				ft_kill (pid, SIGUSR1);
			else
				ft_kill (pid, SIGUSR2);
			num_bit --;
			usleep (100);
		}
		msg ++;
	}
}

static void	receive_msg(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd ("Character Received Successfully!\n", 1);
}

static void	initsig(void)
{
	struct sigaction	init;

	init.sa_handler = receive_msg;
	if (sigaction (SIGUSR1, &init, NULL) == -1)
	{
		ft_putstr_fd ("Set Signal Error: SIGNAL_1\n", 1);
		exit (EXIT_FAILURE);
	}
}

int	main(int arc, char **arg)
{
	pid_t	pid;

	initsig ();
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
