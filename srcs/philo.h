/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:59:28 by chsiffre          #+#    #+#             */
/*   Updated: 2023/02/28 16:59:59 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_data
{
	int         n_philo;
	int         time_die;
	int         time_eat;
	int         time_sleep;
	int         option_eat;
	pthread_mutex_t	*l_fork;
	long long   time;
	
}   t_data;

typedef struct s_philo
{
	int             i;
	pthread_t       philo;
	t_data          *data;
	
}   t_philo;

int     		main(int ac, char **av);
void			ft_create_philo(t_data *data);
long long int   ft_time(void);
void    ft_struct_init(t_data *data, int ac, char **av);
void    *ft_routine(t_philo *phil);
long long	ft_atoi(const char	*str);


#endif
