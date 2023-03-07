/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:13 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/07 09:22:34 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;
    pthread_t   *philo;
    int         i;
    
    i = -1;
    if (ac < 5)
        return (printf("number of arugment invalid\n"), 0);
    data = ft_struct_init(ac, av);
    if (!data)
        return (0);
    ft_mutex_init(data);
    philo = ft_create_philo(data);
    while (++i < data->n_philo)
        pthread_join(philo[i], NULL);
    i = -1;
    while (++i < data->n_philo)
        pthread_mutex_destroy(&data->fork[i]);
    return (0);
}
