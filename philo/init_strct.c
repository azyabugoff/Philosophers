/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_strct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:27:41 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/07/23 18:21:17 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosophers.h"

void	init_mutex(t_strct *strct)
{
	int	i;

	i = 0;
	while (i < strct->n_phils)
	{
		pthread_mutex_init(&strct->forks[i], NULL);
		++i;
	}
	pthread_mutex_init(&strct->print, NULL);
}

static int	init_params(t_strct *strct, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (print_err("Error: Wrong number of arguments.\n"));
	if (!str_all_digits(argv[1]) || !str_all_digits(argv[2])
		|| !str_all_digits(argv[3]) || !str_all_digits(argv[4]))
		return (print_err("Error: Wrong arguments.\n"));
	if (argc == 6 && !str_all_digits(argv[5]))
		return (print_err("Error: Wrong arguments.\n"));
	strct->n_phils = ft_atoi(argv[1]);
	if (strct->n_phils < 1)
		return (print_err("Error: Wrong number of philosophers.\n"));
	strct->t_to_die = ft_atoi(argv[2]);
	strct->t_to_eat = ft_atoi(argv[3]);
	strct->t_to_sleep = ft_atoi(argv[4]);
	if (strct->t_to_die <= 0 || strct->t_to_eat <= 0 || strct->t_to_sleep <= 0)
		return (print_err("Error: Wrong arguments.\n"));
	if (argc == 6)
	{
		strct->n_meals = ft_atoi(argv[5]);
		if (strct->n_meals <= 0)
			return (print_err("Error: Wrong n of meals each philo must eat.\n"));
	}
	else
		strct->n_meals = -1;
	return (0);
}

static void	give_forks_to_phil(t_strct *strct, int i)
{
	if (strct->phils[i].ind % 2 != 0)
		strct->phils[i].is_even = 0;
	else
		strct->phils[i].is_even = 1;
	strct->phils[i].l_fork = &strct->forks[i];
	if (i == strct->n_phils - 1)
		strct->phils[i].r_fork = &strct->forks[0];
	else
		strct->phils[i].r_fork = &strct->forks[i + 1];
}

static int	init_phils(t_strct *strct)
{
	int	i;

	strct->phils = (t_phil *)malloc(sizeof(t_phil) * strct->n_phils);
	if (!strct->phils)
	{
		free(strct->th);
		free(strct->forks);
		return (print_err("Error: Malloc error.\n"));
	}
	i = 0;
	while (i < strct->n_phils)
	{
		strct->phils[i].ind = i + 1;
		strct->phils[i].finished = 0;
		strct->phils[i].st_process = cur_time();
		strct->phils[i].t_to_eat = strct->t_to_eat;
		strct->phils[i].t_to_die = strct->t_to_die;
		strct->phils[i].t_to_sleep = strct->t_to_sleep;
		strct->phils[i].n_meals = strct->n_meals;
		strct->phils[i].thread = &strct->th[i];
		strct->phils[i].print = &strct->print;
		give_forks_to_phil(strct, i);
		++i;
	}
	return (0);
}

int	init_strct(t_strct *strct, char **argv, int argc)
{
	if (init_params(strct, argc, argv) != 0)
		return (1);
	strct->th = (pthread_t *)malloc(sizeof(pthread_t) * strct->n_phils);
	if (!strct->th)
		return (print_err("Error: Malloc error.\n"));
	strct->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * strct->n_phils);
	if (!strct->forks)
	{
		free(strct->th);
		return (print_err("Error: Malloc error.\n"));
	}
	init_mutex(strct);
	if (init_phils(strct) != 0)
		return (1);
	return (0);
}
