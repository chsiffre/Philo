/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:59:28 by chsiffre          #+#    #+#             */
/*   Updated: 2023/03/08 13:41:28 by charles          ###   ########.fr       */
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

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "is dead"

typedef struct s_data
{
	int				n_philo;
	long			start_time;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				option_eat;
	int				philo_dead;
	pthread_mutex_t	dead;
	pthread_mutex_t	print;
	pthread_mutex_t	*fork;
	long			time;
	
}   t_data;

typedef struct s_philo
{
	int             i_phil;
	int				eat_count;
	long			last_eat;
	int				l_fork;
	int				r_fork;
	t_data          *data;
	
	
}   t_philo;

int     		main(int ac, char **av);
pthread_t		*ft_create_philo(t_data *data, t_philo *phil);
t_philo			ft_philo_var_init(int i, t_data *data);
long			actual_time(long start_time);
void			safe_print(t_philo *phil, char *str);
t_data			*ft_struct_init(int ac, char **av);
void			*ft_routine(void *phil);
long long		ft_atoi(const char	*str);
pthread_mutex_t *ft_create_fork(int n_philo);
void			ft_mutex_init(t_data *data);
void			ft_lock_fork(t_philo *phil);
void			ft_unlock_fork(t_philo *phil);
int				philo_sleep(t_philo *phil);
int				philo_eat(t_philo *phil);
int				is_dead(t_philo *phil);
void			shot_time(t_philo *phil, long time_wait);
void			ft_free(pthread_t *philo, t_data *data, t_philo *phil);
void			ft_mutex_destroy(t_data *data);

#endif
