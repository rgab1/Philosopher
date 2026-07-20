/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:17:35 by grivault          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/14 05:49:44 by grivault         ###   ########.fr       */
=======
/*   Updated: 2026/07/20 19:04:01 by grivault         ###   ########.fr       */
>>>>>>> 424eb4fddf7d4cff45604be900a80e916d5db8e2
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
