/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:03:31 by charles           #+#    #+#             */
/*   Updated: 2023/03/05 19:06:42 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t *ft_create_fork(int n_philo)
{
	pthread_mutex_t	*fork;
	int				i;
	
	fork = malloc(sizeof(pthread_mutex_t) * n_philo);
	if (!fork)
		return (NULL);
	i = -1;
	while (++i < n_philo)
		pthread_mutex_init(&fork[i], NULL);
	return (fork);
}