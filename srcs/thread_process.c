/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:35:11 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/05 19:21:52 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_routine(t_philo *phil)
{
    //long long time;
    int        ind;

    ind  = 1;
    printf("%d", phil->data->option_eat);
    //return ((void*)0);
    while (phil->eat_count != phil->data->option_eat )
    {
        phil->eat_count = 0;
        if (philo_eat(phil) == 0)
        {
            if (philo_sleep(phil) == 0)
                return (phil);
        }
        if (philo_is_dead(phil) == 0)
            return (phil)
    }
    return (phil);
}

long    actual_time(long start_time)
{
    return (ft_time() - start_time);
}

void    safe_print(t_philo *phil, int i, char *str)
{
    pthread_mutex_lock(&phil[i].data->fork[phil[i].l_fork]);
    printf("%ld %d %s", actual_time(phil[i].data->start_time),  phil[i].i_phil, str);
    pthread_mutex_lock(&phil[i].data->fork[phil[i].r_fork]);
    printf("%ld %d %s", actual_time(phil[i].data->start_time),  phil[i].i_phil, str);
    pthread_mutex_unlock(&phil[i].data->fork[phil[i].l_fork]);
    pthread_mutex_unlock(&phil[i].data->fork[phil[i].r_fork]);
}