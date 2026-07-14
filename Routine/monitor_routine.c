/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 05:51:28 by grivault          #+#    #+#             */
/*   Updated: 2026/07/14 05:51:09 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

static int	check_status(t_philo *philo, int *full_count)
{
	long	time_since_meal;

	pthread_mutex_lock(&philo->meal_mutex);
	time_since_meal = get_current_time() - philo->last_meal_time;
	if (philo->table->max_meals != -1)
	{
		if (philo->meals_eaten >= philo->table->max_meals)
			(*full_count)++;
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	if (time_since_meal >= philo->table->time_to_die)
		return (1);
	return (0);
}

static void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->sync_mutex);
	philo->table->sim_stop = 1;
	pthread_mutex_unlock(&philo->table->sync_mutex);
	pthread_mutex_lock(&philo->table->write_mutex);
	printf("%ld %d died\n", get_current_time() - philo->table->start_time,
		philo->id);
	pthread_mutex_unlock(&philo->table->write_mutex);
}

void	monitor_routine(t_philo *philos)
{
	t_table	*table;
	int		i;
	int		full_count;

	table = philos[0].table;
	while (!check_sim_stop(table))
	{
		i = 0;
		full_count = 0;
		while (i < table->num_philos)
		{
			if (check_status(&philos[i], &full_count))
				return (print_death(&philos[i]));
			i++;
		}
		if (full_count == table->num_philos)
		{
			pthread_mutex_lock(&table->sync_mutex);
			table->sim_stop = 1;
			pthread_mutex_unlock(&table->sync_mutex);
			return ;
		}
		usleep(1000);
	}
}
