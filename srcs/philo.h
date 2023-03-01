/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:59:28 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/01 17:19:39 by charles          ###   ########.fr       */
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
	int			start_time;
	int         time_die;
	int         time_eat;
	int         time_sleep;
	int         option_eat;
	pthread_mutex_t	*fork;
	long long   time;
	
}   t_data;

typedef struct s_philo
{
	int             i_phil;
	int				eat_count;
	int				last_eat;
	int				left_fork;
	int				right_fork;
	t_data          *data;
	
	
}   t_philo;

int     		main(int ac, char **av);
pthread_t		*ft_create_philo(t_data *data);
t_philo			ft_philo_var_init(int i, t_data *data);
long long int   ft_time(void);
void			ft_struct_init(t_data *data, int ac, char **av);
void			*ft_routine(t_philo *phil);
long long		ft_atoi(const char	*str);
pthread_mutex_t *ft_create_fork(int n_philo);


#endif
