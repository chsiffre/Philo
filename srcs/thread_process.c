/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:35:11 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/02 14:31:44 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_routine(t_philo *phil)
{
    long long time;
    int        ind;

    ind  = 1;
    //printf("%d", phil->data->option_eat);
    printf("%d", phil->data->option_eat);
    while (++ind != phil->data->option_eat )//|| !ft_isdead())
    {
        //if (phil->data->option_eat % 2 == 1)
        dprintf(2, "ok");
        safe_print(&phil[ind], ind, FORK);    
    }
    return ((void * ) 0);
}

long    actual_time(long start_time)
{
    return (ft_time() - start_time);
}

void    safe_print(t_philo *phil, int i, char *str)
{
    dprintf(2, " safe_print");
    pthread_mutex_lock(&phil[i].data->fork[phil[i].l_fork]);
    printf("%ld %d %s", actual_time(phil[i].data->start_time),  phil[i].i_phil, str);
    pthread_mutex_lock(&phil[i].data->fork[phil[i].r_fork]);
    printf("%ld %d %s", actual_time(phil[i].data->start_time),  phil[i].i_phil, str);
    pthread_mutex_unlock(&phil[i].data->fork[phil[i].l_fork]);
    pthread_mutex_unlock(&phil[i].data->fork[phil[i].r_fork]);
}