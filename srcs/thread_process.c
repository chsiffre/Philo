/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:35:11 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/08 13:14:28 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_routine(void *param)
{
    t_philo *phil;

    phil = (t_philo *) param;
    if (phil->data->n_philo == 1)
    {
        safe_print(phil, FORK);
        usleep((phil->data->time_die)* 1000);
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

void    safe_print(t_philo *phil, char *str)
{
    pthread_mutex_lock(&phil->data->dead);
    if (phil->data->philo_dead == 1)
    {
        pthread_mutex_unlock(&phil->data->dead);
        return ;
    }
    pthread_mutex_unlock(&phil->data->dead);
    pthread_mutex_lock(&phil->data->print);
    printf("%ld %d %s\n", actual_time(phil->data->start_time), phil->i_phil, str);
    pthread_mutex_unlock(&phil->data->print);
}

int philo_eat(t_philo *phil)
{
    if (is_dead(phil))
        return (1);
    ft_lock_fork(phil);
    safe_print(phil, FORK);
    safe_print(phil, FORK);
    pthread_mutex_lock(&phil->data->dead);
    if (actual_time(phil->data->start_time) - phil->last_eat > phil->data->time_die || phil->data->philo_dead == 1)
    {
        pthread_mutex_unlock(&phil->data->dead);
        ft_unlock_fork(phil);
        return (1);
    }
    pthread_mutex_unlock(&phil->data->dead);
    safe_print(phil, EAT);
    phil->last_eat = actual_time(phil->data->start_time);
    shot_time(phil ,phil->data->time_eat);
    phil->eat_count++;
    ft_unlock_fork(phil);
    return (0);
}

int philo_sleep(t_philo *phil)
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

int    is_dead(t_philo *phil)
{
    pthread_mutex_lock(&phil->data->dead);
    if ((actual_time(phil->data->start_time) - phil->last_eat > phil->data->time_die 
            && phil->data->philo_dead == 0 )|| phil->data->n_philo == 1)
    {
        phil->data->philo_dead = 1;
        pthread_mutex_lock(&phil->data->print);
        printf("%ld %d %s\n", actual_time(phil->data->start_time), phil->i_phil, DEAD);
        pthread_mutex_unlock(&phil->data->print);
    }
    pthread_mutex_unlock(&phil->data->dead);
    if (phil->data->philo_dead == 1)
        return (1);
    return (0);
}