/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:56:13 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/09 13:38:20 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		*data;
	pthread_t	*philo;
	t_philo		*phil;
	int			i;

	i = -1;
	if (ac != 6 && ac != 5)
		return (printf("number of arugment invalid\n"), 0);
	ft_parsing(ac, av);
	data = ft_struct_init(ac, av);
	if (!data)
		return (0);
	phil = malloc(sizeof(t_philo) * data->n_philo);
	if (!phil)
		return (free(data), 0);
	ft_mutex_init(data);
	philo = ft_create_philo(data, phil);
	if (!philo)
		return (free(data), 0);
	while (++i < data->n_philo)
		pthread_join(philo[i], NULL);
	ft_mutex_destroy(data);
	ft_free(philo, data, phil);
	return (0);
}
