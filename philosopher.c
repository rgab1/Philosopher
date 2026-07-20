/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:17:35 by grivault          #+#    #+#             */
/*   Updated: 2026/07/20 20:51:45 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	main(int ac, char **av)
{
	t_table	*table;
	t_philo	*philos;
	int		i;

	table = table_init(ac, av);
	if (!table)
		return (1);
	philos = philosophers_init(table);
	if (!philos)
		return (table_cleanup(table), 1);
	table->start_time = get_current_time();
	i = 0;
	while (i < table->num_philos)
	{
		philos[i].last_meal_time = table->start_time;
		pthread_create(&philos[i].thread_id, NULL, &philosopher_routine,
			&philos[i]);
		i++;
	}
	monitor_routine(philos);
	i = 0;
	while (i < table->num_philos)
		pthread_join(philos[i++].thread_id, NULL);
	full_cleanup(philos);
	return (0);
}
