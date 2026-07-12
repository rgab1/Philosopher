/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:28:22 by grivault          #+#    #+#             */
/*   Updated: 2026/07/12 16:37:02 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_table {
    int             num_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             max_meals;
    int             sim_stop;
    long            start_time;
    pthread_mutex_t write_mutex;
    pthread_mutex_t sync_mutex;
    pthread_mutex_t *forks;
} t_table;

typedef struct s_philo {
    int             id;
    int             meals_eaten;
    long            last_meal_time;
    pthread_t       thread_id;
	pthread_mutex_t meal_mutex;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    t_table         *table;
} t_philo;

void	put_error(char *error_str);
void	put_error_mutex_lock(char *error_str, t_table *table);
void	ft_putstr_fd(char *str, int fd);
long	get_current_time(void);

t_philo	*philosopher_init(t_table *table);
t_table	*table_init(int num_philos, int time_to_die, int time_to_eat,
					int time_to_sleep);


