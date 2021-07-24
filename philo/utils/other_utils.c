/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesnowbi <sesnowbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:57:05 by sesnowbi          #+#    #+#             */
/*   Updated: 2021/07/23 17:52:58 by sesnowbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

char	*ft_strdup(char *s1)
{
	int		size;
	char	*s;
	int		i;

	i = 0;
	size = ft_strlen(s1);
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (NULL);
	else
	{
		while (s1[i])
		{
			s[i] = s1[i];
			++i;
		}
	}
	s[i] = '\0';
	return (s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	memset(ptr, 0, count * size);
	return (ptr);
}

int	str_all_digits(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	return (1);
}

void	free_strct(t_strct *strct)
{
	if (strct->th)
		free(strct->th);
	if (strct->forks)
		free(strct->forks);
	if (strct->phils)
		free(strct->phils);
}
