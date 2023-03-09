/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:35:11 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/09 12:09:26 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *param)
{
	t_philo	*phil;

	phil = (t_philo *) param;
	if (phil->data->n_philo == 1)
	{
		safe_print(phil, FORK);
		usleep((phil->data->time_die) * 1000);
		if (is_dead(phil))
			return (0);
	}
	if (phil->i_phil % 2)
		usleep(15000);
	while (phil->eat_count != phil->data->option_eat)
	{
		if (philo_eat(phil) == 0)
		{
			if (philo_sleep(phil))
				return (phil);
		}
		if (is_dead(phil))
			return (phil);
	}
	return (phil);
}

void	safe_print(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->data->dead);
	if (p->data->philo_dead == 1)
	{
		pthread_mutex_unlock(&p->data->dead);
		return ;
	}
	pthread_mutex_lock(&p->data->print);
	printf("%ld %d %s\n", actual_time(p->data->start_time), p->i_phil, str);
	pthread_mutex_unlock(&p->data->dead);
	pthread_mutex_unlock(&p->data->print);
}

int	philo_eat(t_philo *p)
{
	if (is_dead(p))
		return (1);
	ft_lock_fork(p);
	safe_print(p, FORK);
	safe_print(p, FORK);
	pthread_mutex_lock(&p->data->dead);
	if (actual_time(p->data->start_time) - p->last_eat > p->data->time_die
		|| p->data->philo_dead == 1)
	{
		pthread_mutex_unlock(&p->data->dead);
		ft_unlock_fork(p);
		return (1);
	}
	pthread_mutex_unlock(&p->data->dead);
	safe_print(p, EAT);
	p->last_eat = actual_time(p->data->start_time);
	shot_time(p, p->data->time_eat);
	p->eat_count++;
	ft_unlock_fork(p);
	return (0);
}

int	philo_sleep(t_philo *phil)
{
	if (is_dead(phil))
		return (1);
	safe_print(phil, SLEEP);
	shot_time(phil, phil->data->time_sleep);
	if (is_dead(phil))
		return (1);
	safe_print(phil, THINK);
	return (0);
}

int	is_dead(t_philo *p)
{
	pthread_mutex_lock(&p->data->dead);
	if ((actual_time(p->data->start_time) - p->last_eat > p->data->time_die
			&& p->data->philo_dead == 0) || p->data->n_philo == 1)
	{
		p->data->philo_dead = 1;
		pthread_mutex_lock(&p->data->print);
		printf("%ld %d %s\n", actual_time(p->data->start_time), p->i_phil, DEAD);
		pthread_mutex_unlock(&p->data->print);
	}
	pthread_mutex_unlock(&p->data->dead);
	if (p->data->philo_dead == 1)
		return (1);
	return (0);
}
