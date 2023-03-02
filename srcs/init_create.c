/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:10:22 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/02 14:08:38 by chsiffre         ###   ########.fr       */
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
    if (!philo)
        return (NULL);
    data->fork = ft_create_fork(data->n_philo);
    i = -1;
    while (++i < data->n_philo)
    {
        phil[i] = ft_philo_var_init(i + 1, data);
        //dprintf(2, "ok");
        //printf("Le philo %d aura la fourchette gauche %d et la fourchette droite %d\n", phil[i].i_phil, phil[i].l_fork, phil[i].r_fork);
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
    if (i == 1)
    {
        phil->r_fork = data->n_philo;
        phil->l_fork = i;
    }
    else
    {
        phil->r_fork = i - 1;
        phil->l_fork = i;
    }   
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