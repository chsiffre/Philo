/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:56:20 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/08 13:41:46 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_mutex_init(t_data *data)
{
    pthread_mutex_init(&data->print, NULL);
    pthread_mutex_init(&data->dead, NULL);
}


long    actual_time(long start_time)
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    return ((time.tv_usec * 0.001 + time.tv_sec * 1000) - start_time);
}

void    shot_time(t_philo *phil, long time_wait)
{
    int time;
    
    time = actual_time(phil->data->start_time);
    if (time - phil->last_eat + time_wait > phil->data->time_die)
		usleep((phil->data->time_die - (time - phil->last_eat) + 1) * 1000);
	else
		usleep(time_wait * 1000);
}

void    ft_free(pthread_t *philo, t_data *data, t_philo *phil)
{
    free(philo);
    free(data->fork);
    free(data);
    free(phil);
}

void    ft_mutex_destroy(t_data *data)
{
    int i;
    
    i = -1;
    while (++i < data->n_philo)
        pthread_mutex_destroy(&data->fork[i]);
    pthread_mutex_destroy(&data->dead);
    pthread_mutex_destroy(&data->print);
}