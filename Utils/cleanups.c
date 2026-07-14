/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:56:14 by grivault          #+#    #+#             */
/*   Updated: 2026/07/14 05:45:48 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	table_cleanup(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
		pthread_mutex_destroy(&table->forks[i++]);
	pthread_mutex_destroy(&table->write_mutex);
	pthread_mutex_destroy(&table->sync_mutex);
	free(table->forks);
	free(table);
}

void	philos_cleanup(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].table->num_philos)
		pthread_mutex_destroy(&philos[i++].meal_mutex);
	free(philos);
}

void	full_cleanup(t_philo *philos)
{
	t_table	*table;

	table = philos[0].table;
	philos_cleanup(philos);
	table_cleanup(table);
}
