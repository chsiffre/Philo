/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:13 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/01 17:16:07 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;
    pthread_t   *philo;
    
    if (ac < 5)
        return (printf("number of arugment invalid\n"), 0);
    printf("ok");
    data = malloc(sizeof(t_data));
    if (!data)
        return (0);
    ft_struct_init(data, ac, av);
    printf("ok");
    philo = ft_create_philo(data);
    return (0);
    
}
