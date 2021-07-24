/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:55:44 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/07/23 19:12:44 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

int	create_threads(t_strct *strct)
{
	int	i;

	i = 0;
	while (i < strct->n_phils)
	{
		if (pthread_create(&strct->th[i], NULL,
				&main_handler, &strct->phils[i]))
			return (print_err("Error: Failed to create thread.\n"));
		++i;
	}
	return (0);
}

static int	check_died_finished(t_strct *strct, int i)
{
	if (strct->phils[i].t_to_die < time_diff(strct->phils[i].last_meal))
	{
		pthread_mutex_lock(&strct->print);
		printf("%lld %d died\n",
			time_diff(strct->phils[0].st_process), strct->phils[i].ind);
		return (0);
	}
	else if (strct->phils[i].finished == 1)
		return (0);
	return (1);
}

int	monitor(t_strct *strct)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < strct->n_phils)
		{
			if (check_died_finished(strct, i) != 1)
				return (0);
			++i;
		}
	}
	return (0);
}

int	exec_threads(t_strct *strct)
{
	if (create_threads(strct) != 0)
		return (1);
	sleeping(10);
	return (monitor(strct));
}
