/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:15:41 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/09 13:38:04 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_parsing(int ac, char **av)
{
	int	i;
	int	x;

	i = 0;
	while (++i < ac)
	{
		x = -1;
		while (av[i][++x])
			if (!ft_isdigit(av[i][x]))
				return (printf("Invalid argument\n"), exit(1));
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
