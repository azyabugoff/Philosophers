/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:37:05 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/07/23 16:26:25 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_tern_i(int cond, int ret_true, int ret_false)
{
	if (cond)
		return (ret_true);
	else
		return (ret_false);
}

long long	ft_ternar_ll(int cond, long long ret_true, long long ret_false)
{
	if (cond)
		return (ret_true);
	else
		return (ret_false);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
		++i;
	return (i);
}

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	long long	res;
	int			is_neg;

	is_neg = 0;
	res = 0;
	while (*str == '0')
		++str;
	while (res <= MAX_INT && ft_isdigit(*str))
	{
		res *= 10;
		res += *str - '0';
		++str;
	}
	if (is_neg)
		return (ft_tern_i((-res < MIN_INT), 0, -res));
	return (ft_tern_i((res > MAX_INT), -1, res));
}
