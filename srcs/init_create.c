/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:10:22 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/01 18:22:17 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t    *ft_create_philo(t_data *data)
{
    pthread_t   *philo;
    t_philo     *phil;
    int i;
    
    philo = malloc(sizeof(pthread_t) * data->n_philo);
    if (!philo)
        return (NULL);
    phil = malloc(sizeof(t_philo) * data->n_philo);
    data->fork = ft_create_fork(data->n_philo);
    i = -1;
    while (++i < data->n_philo)
    {
        phil[i] = ft_philo_var_init(i + 1, data);
        pthread_create(&philo[i], NULL, (void *) ft_routine, &phil[i]);
    }
    return (philo);
}

t_philo ft_philo_var_init(int i, t_data *data)
{
    t_philo *phil;
    
    phil = malloc(sizeof(t_philo));
    if (!phil)
        return (*phil);
    phil->i_phil = i;
    phil->eat_count = 0;
    phil->last_eat = data->start_time;
    return (*phil);
    
}

void    ft_struct_init(t_data *data, int ac, char **av)
{
    struct timeval  time;
    data->n_philo = ft_atoi(av[1]);
    data->time_die = ft_atoi(av[2]);
    data->time_eat = ft_atoi(av[3]);
    if (ac == 6)
        data->option_eat = ft_atoi(av[4]);
    else
        data->option_eat = -1;
    
    gettimeofday(&time, NULL);
    data->start_time = (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long int   ft_time(void)
{
    struct timeval current_time;
    
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void *ft_routine(t_philo *phil)
{
    // long long time;

    // printf("%d ", phil->i);
    // time = ft_time();
    // pthread_mutex_lock(phil->data->l_fork);
    // printf("%lld %d has taken a fork\n", time - ft_time(), phil->i);
    // pthread_mutex_unlock(phil->data->l_fork);
    pthread_mutex_lock(phil->r_fork);
    // printf("%lld %d has taken a fork\n", time - ft_time(), phil->i);
    // pthread_mutex_unlock(phil->r_fork);
    return ((void * ) 0);
}