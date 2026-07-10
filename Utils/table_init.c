/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:33:28 by grivault          #+#    #+#             */
/*   Updated: 2026/07/10 20:43:35 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

static void	fork_mutex_failed(int i, t_table *table)
{
	while (--i >= 0)
		pthread_mutex_destroy(&table->forks[i]);
	free(table->forks);
	return ();// a gerer un message d'erreur disant que pthread_mutex_init a fail
}

static int	mutex_init(t_table *table)
{
	int	i;

	i = 0;
	if (!table->forks)
		return (1); // a gerer un message d'erreur disant que malloc a fail
	while (i < table->num_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (fork_mutex_failed(i, table), 1);
		i++;
	}
	if (pthread_mutex_init(&table->write_mutex, NULL) != 0)
		return (fork_mutex_failed(i, table), 1);
	if (pthread_mutex_init(&table->sync_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&table->write_mutex);
		return (fork_mutex_failed(i, table), 1);
	}
	return (0);
}

t_table	*table_init(int num_philos, int time_to_die, int time_to_eat,
		int time_to_sleep)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL); // a gerer un message d'erreur disant que malloc a fail
	table->num_philos = num_philos;
	table->time_to_die = time_to_die;
	table->time_to_eat = time_to_eat;
	table->time_to_sleep = time_to_sleep;
	table->sim_stop = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (mutex_init(table))
		return (free(table), NULL);
	return (table);
}
