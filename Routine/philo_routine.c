/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 05:10:41 by grivault          #+#    #+#             */
/*   Updated: 2026/07/20 20:29:41 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->num_philos == 1)
	{
		pthread_mutex_lock(philo->first_fork);
		print_action("has taken a fork", philo);
		usleep(philo->table->time_to_die * 1000);
		pthread_mutex_unlock(philo->first_fork);
		return (NULL);
	}
	smart_sleep(STAGGER(philo->id, philo->table->time_to_eat), philo->table);
	while (!check_sim_stop(philo->table))
	{
		philo_eat(philo);
		if (check_sim_stop(philo->table))
			break ;
		print_action("is sleeping", philo);
		smart_sleep(philo->table->time_to_sleep, philo->table);
		if (check_sim_stop(philo->table))
			break ;
		print_action("is thinking", philo);
		usleep(500);
	}
	return (NULL);
}
