/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:33:28 by grivault          #+#    #+#             */
/*   Updated: 2026/07/12 17:06:38 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

static void	fork_mutex_failed(int i, t_table *table)
{
	while (--i >= 0)
		pthread_mutex_destroy(&table->forks[i]);
	return (put_error(ERROR_MUTEX_INIT_FAILED));
}

static int	mutex_init(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&table->write_mutex, NULL) != 0)
		return (put_error(ERROR_MUTEX_INIT_FAILED), 1);
	if (pthread_mutex_init(&table->sync_mutex, NULL) != 0)
		return (pthread_mutex_destroy(&table->write_mutex),
			   put_error(ERROR_MUTEX_INIT_FAILED), 1);
	while (i < table->num_philos)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			pthread_mutex_destroy(&table->sync_mutex);
			pthread_mutex_destroy(&table->write_mutex);
			return (fork_mutex_failed(i, table), 1);
		}
		i++;
	}
	return (0);
}

t_table	*table_init(int ac, char **av)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (put_error(ERROR_MALLOC_FAILED);l
	if (parsing(ac, av, table))
		return (NULL); // a gerer parsing a fail
	table->start_time = 0;
	table->sim_stop = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->num_philos);
	if (!table->forks)
		return (put_error(ERROR_MALLOC_FAILED), free(table), NULL);
	if (mutex_init(table))
		return (free(table->forks), free(table), NULL);
	return (table);
}
