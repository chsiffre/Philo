/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:35:11 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/06 16:50:17 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_routine(void *param)
{
    t_philo *phil;

    //printf("pre pointer = %p\n", param);
    phil = (t_philo *) param;
    while (phil->eat_count != phil->data->option_eat )
    {
        if (philo_eat(phil) == 1)
        {
            if (philo_sleep(phil) == 1)
                return (phil);
        }
    }
    return (phil);
}

void    safe_print(t_philo *phil, char *str)
{
    pthread_mutex_lock(&phil->data->dead);
    //if (is_alive())
    //{
        //pthread_mutex_unlock(&phil->data->dead);
        //return (1);
    //}
    pthread_mutex_unlock(&phil->data->dead);
    pthread_mutex_lock(&phil->data->print);
    printf("%ld %d %s\n", actual_time(phil->data->start_time), phil->i_phil, str);
    pthread_mutex_unlock(&phil->data->print);
}

int philo_eat(t_philo *phil)
{
    ft_lock_fork(phil);
    safe_print(phil, FORK);
    safe_print(phil, FORK);
    pthread_mutex_lock(&phil->data->dead);
    // if (is_alive())
    // {
    //     pthread_mutex_unlock(&phil->data->dead);
    //     return (1);
    // }
    pthread_mutex_unlock(&phil->data->dead);
    safe_print(phil, EAT);
    usleep(phil->data->time_eat);
    phil->eat_count++;
    ft_unlock_fork(phil);
    return (0);
}

int philo_sleep(t_philo *phil)
{
    safe_print(phil, SLEEP);
    usleep(phil->data->time_sleep);
    safe_print(phil, THINK);
    return (0);
}