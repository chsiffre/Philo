/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:56:20 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/07 10:08:41 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_mutex_init(t_data *data)
{
    pthread_mutex_init(&data->print, NULL);
    pthread_mutex_init(&data->dead, NULL);
}

long    ft_time(void)
{
    struct timeval time;
    
    gettimeofday(&time, NULL);
    return (time.tv_usec * 0.001 + time.tv_sec * 1000);
}

long    actual_time(long start_time)
{
    return (ft_time() - start_time);
}