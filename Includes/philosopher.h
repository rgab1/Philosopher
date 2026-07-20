/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:28:22 by grivault          #+#    #+#             */
/*   Updated: 2026/07/20 22:48:37 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# include <errors.h>
# include <routine.h>

typedef struct s_table
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				sim_stop;
	long			start_time;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	sync_mutex;
	pthread_mutex_t	*forks;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread_id;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*second_fork;
	pthread_mutex_t	*first_fork;
	t_table			*table;
}	t_philo;

void	table_cleanup(t_table *table);
void	philos_cleanup(t_philo *philos);
void	full_cleanup(t_philo *philos);

int		ft_atoi(const char *str);
void	put_error(char *error_str);
void	put_error_mutex_lock(char *error_str, t_table *table);
void	ft_putstr_fd(char *str, int fd);
long	get_current_time(void);

int		parsing(int ac, char **av, t_table *table);
t_philo	*philosophers_init(t_table *table);
t_table	*table_init(int ac, char **av);

#endif
