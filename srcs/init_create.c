/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:10:22 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/28 17:07:06 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_struct_init(t_data *data, t_philo *phil, int ac, char **av)
{
    phil = malloc(sizeof())
    data = malloc(sizeof(t_data));
    if (!data)
        return (0);
    data->n_philo = ft_atoi(av[1]);
    data->time_die = ft_atoi(av[2]);
    data->time_eat = ft_atoi(av[3]);
    if (ac == 6)
        data->option_eat = ft_atoi(av[4]);
    else
        data->option_eat = -1;
}

void    ft_create_philo(t_data *data)
{
    t_philo *phil;
    int i;
    
    phil = malloc(sizeof(t_philo) * data->n_philo);
    if (!phil)
        return ;
    i = -1;
    while (++i < data->n_philo)
    {
        //printf("%d\n", phil->i);
        
        pthread_mutex_init(&phil[i].l_fork, NULL);
        pthread_create(&phil[i].philo, NULL, (void *) ft_routine, &phil[i]);
        phil->i = i + 1;
    }
}

long long int   ft_time(void)
{
    struct timeval current_time;
    
    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void *ft_routine(t_philo *phil)
{
    //long long time;

    printf("%d ", phil->i);
   // time = ft_time();
    pthread_mutex_lock(phil->data->l_fork);
    //printf("%lld %d has taken a fork\n", time - ft_time(), phil->i);
    pthread_mutex_unlock(phil->data->l_fork);
    pthread_mutex_lock(phil->r_fork);
    //printf("%lld %d has taken a fork\n", time - ft_time(), phil->i);
    pthread_mutex_unlock(phil->r_fork);
    return ((void * ) 0);
}