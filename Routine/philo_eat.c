/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 05:15:38 by grivault          #+#    #+#             */
/*   Updated: 2026/07/13 08:00:34 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->first_fork);
	print_action("has taken a fork", philo);
	pthread_mutex_lock(philo->second_fork);
	print_action("has taken a fork", philo);
	print_action("is eating", philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	smart_sleep(philo->table->time_to_eat, philo->table);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}
