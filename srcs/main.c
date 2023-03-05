/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:13 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/05 18:49:10 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;
    t_philo *phil;
    pthread_t   *philo;
    
    if (ac < 5)
        return (printf("number of arugment invalid\n"), 0);
    data = ft_struct_init(ac, av);
    if (!data)
        return (0);
    philo = ft_create_philo(data);
    return (0);
    
}
