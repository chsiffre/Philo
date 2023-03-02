/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:13 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/02 10:40:40 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;
    pthread_t   *philo;
    
    if (ac < 5)
        return (printf("number of arugment invalid\n"), 0);
    data = malloc(sizeof(t_data));
    if (!data)
        return (0);
    ft_struct_init(data, ac, av);
    philo = ft_create_philo(data);
    return (0);
    
}
