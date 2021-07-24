/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:42:03 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/07/23 16:30:29 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	print_action(t_phil *phil, char *str)
{
	pthread_mutex_lock(phil->print);
	if (str)
		printf("%lld %d %s\n", time_diff(phil->st_process), phil->ind, str);
	pthread_mutex_unlock(phil->print);
}

void	*main_handler(void *arg)
{
	t_phil	*phil;

	phil = (t_phil *)arg;
	phil->last_meal = cur_time();
	if (phil->is_even)
		sleeping(phil->t_to_eat / 2);
	while (phil->n_meals)
	{
		print_action(phil, "is thinking");
		pthread_mutex_lock(phil->r_fork);
		print_action(phil, "has taken a fork");
		pthread_mutex_lock(phil->l_fork);
		print_action(phil, "has taken a fork");
		phil->last_meal = cur_time();
		print_action(phil, "is eating");
		eating(phil);
		pthread_mutex_unlock(phil->l_fork);
		pthread_mutex_unlock(phil->r_fork);
		print_action(phil, "is sleeping");
		sleeping(phil->t_to_sleep);
	}
	phil->finished = 1;
	return (NULL);
}
