/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:13 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/28 17:06:10 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_philo *phil;
    t_data *data;
    
    if (ac < 5)
        return (printf("number of arugment invalid\n"), 0);
    else if (ac >= 5)
    {
        ft_struct_init(data, ac, av);
        ft_create_philo(data);
    }
    return (0);
    
}
