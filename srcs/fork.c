/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:03:31 by charles           #+#    #+#             */
/*   Updated: 2023/03/09 11:53:18 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ft_create_fork(int n_philo)
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

void	ft_lock_fork(t_philo *phil)
{
	if (phil->data->n_philo != 1)
	{
		pthread_mutex_lock(&phil->data->fork[phil->l_fork]);
		pthread_mutex_lock(&phil->data->fork[phil->r_fork]);
	}
}

void	ft_unlock_fork(t_philo *phil)
{
	if (phil->data->n_philo != 1)
	{
		pthread_mutex_unlock(&phil->data->fork[phil->l_fork]);
		pthread_mutex_unlock(&phil->data->fork[phil->r_fork]);
	}
}
