/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cliente.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:32:41 by yugao             #+#    #+#             */
/*   Updated: 2024/02/06 21:57:03 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(pid_t id, char *msg)
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
				kill (id, SIGUSR1);
			else
				kill (id, SIGUSR2);
			usleep (50);
			c <<= 1;
		}
		msg ++;
	}
}

int	main(int arc, char **arg)
{
	pid_t	id;

	id = ft_atoi (arg[1]);
	send_msg (id, arg[2]);
	return (0);
}