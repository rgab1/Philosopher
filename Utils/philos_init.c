/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 21:08:49 by grivault          #+#    #+#             */
/*   Updated: 2026/07/14 05:46:25 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

static void	philo_mutex_failed(int i, t_philo *philos)
{
	while (--i >= 0)
		pthread_mutex_destroy(&philos[i].meal_mutex);
	put_error(ERROR_MUTEX_INIT_FAILED);
}

static void	forks_assignation(int i, t_philo *philo)
{
	t_table	*table;

	table = philo->table;
	if ((i + 1) % 2 == 0)
	{
		philo[i].first_fork = &table->forks[i];
		philo[i].second_fork = &table->forks[(i + 1) % table->num_philos];
	}
	else
	{
		philo[i].second_fork = &table->forks[i];
		philo[i].first_fork = &table->forks[(i + 1) % table->num_philos];
	}
}

t_philo	*philosophers_init(t_table *table)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!philos)
		return (put_error(ERROR_MALLOC_FAILED), NULL);
	i = 0;
	while (i < table->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].last_meal_time = 0;
		philos[i].meals_eaten = 0;
		philos[i].table = table;
		forks_assignation(i, philos);
		if (pthread_mutex_init(&philos[i].meal_mutex, NULL) != 0)
			return (philo_mutex_failed(i, philos), free(philos), NULL);
		i++;
	}
	return (philos);
}
