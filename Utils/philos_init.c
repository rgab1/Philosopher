/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 21:08:49 by grivault          #+#    #+#             */
/*   Updated: 2026/07/10 21:27:12 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

static void	philo_mutex_failed(int i, t_philo *philos)
{
	while (--i >= 0)
		pthread_mutex_destroy(&philos[i].meal_mutex);
}

t_philo *philosopher_init(t_table *table)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * table->num_philos);
	if (!philos)
		return (NULL); // a gerer message erreur malloc failed
	i = 0;
	while (i < table->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].last_meal_time = 0;
		philos[i].meals_eaten = 0;
		philos[i].table = table;
		philos[i].left_fork = &table->forks[i];
		philos[i].right_fork = &table->forks[(i + 1) % table->num_philos];
		if (pthread_mutex_init(&philos[i].meal_mutex, NULL) != 0)
			return (philo_mutex_failed(i, philos), free(philos), NULL); //a gerer message erreur mutex failed
		i++;
	}
	return (philos);
}
