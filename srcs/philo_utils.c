/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 11:56:20 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/06 12:01:09 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_mutex_init(t_data *data)
{
    pthread_mutex_init(&data->print, NULL);
    pthread_mutex_init(&data->dead, NULL);
}

long long int   ft_time(void)
{
    struct timeval current_time;
    
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long    actual_time(long start_time)
{
    return (ft_time() - start_time);
}