/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:28:17 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/07/23 12:48:54 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

uint64_t	time_diff(uint64_t time)
{
	return (cur_time() - time);
}

void	sleeping(uint64_t t_to_sleep)
{
	uint64_t	start;

	start = cur_time();
	while (time_diff(start) < t_to_sleep)
		usleep(500);
}

void	eating(t_phil *phil)
{
	uint64_t	start;

	start = cur_time();
	if (phil->n_meals == MIN_INT)
		phil->n_meals = -1;
	phil->n_meals--;
	while (time_diff(start) < phil->t_to_eat)
		usleep(500);
}

uint64_t	cur_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec * 0.001);
}
