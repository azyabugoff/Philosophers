/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 16:37:45 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/07/23 18:12:11 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_phil
{
	int				ind;
	uint64_t		st_process;
	uint64_t		last_meal;
	uint64_t		t_to_eat;
	uint64_t		t_to_die;
	uint64_t		t_to_sleep;
	int				n_meals;
	int				is_even;
	int				finished;
	pthread_t		*thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*print;
}	t_phil;

typedef struct s_strct
{
	int				n_phils;
	uint64_t		t_to_die;
	uint64_t		t_to_eat;
	uint64_t		t_to_sleep;
	int				n_meals;
	pthread_t		*th;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_phil			*phils;
}	t_strct;

int			print_err(char *str);
int			ft_strlen(char *str);
char		*ft_strdup(char *s1);
void		*ft_calloc(size_t count, size_t size);
int			str_all_digits(char *str);
int			ft_tern_i(int cond, int ret_true, int ret_false);
long long	ft_ternar_ll(int cond, long long ret_true, long long ret_false);
int			ft_is_space(char c);
int			ft_isdigit(int c);
int			ft_atoi(char *str);
uint64_t	cur_time(void);
uint64_t	time_diff(uint64_t time);
void		sleeping(uint64_t t_to_sleep);
void		eating(t_phil *phil);
int			init_strct(t_strct *strct, char **argv, int argc);
void		free_strct(t_strct *strct);
void		init_mutex(t_strct *strct);
int			create_threads(t_strct *strct);
int			exec_threads(t_strct *strct);
int			monitor(t_strct *strct);
void		*main_handler(void *arg);
void		print_action(t_phil *phil, char *str);

#endif
