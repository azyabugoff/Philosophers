/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 15:06:34 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/07/23 19:06:09 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	print_err(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

static void	destroy_mutexes(t_strct *strct)
{
	int	i;

	i = 0;
	while (i < strct->n_phils)
	{
		pthread_mutex_destroy(&strct->forks[i]);
		usleep(10);
		++i;
	}
	pthread_mutex_destroy(&strct->print);
}

int	main(int argc, char *argv[])
{
	t_strct	strct;
	int		res;

	if (init_strct(&strct, argv, argc) != 0)
		return (1);
	res = exec_threads(&strct);
	destroy_mutexes(&strct);
	free_strct(&strct);
	return (res);
}
