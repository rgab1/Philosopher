/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 05:38:31 by grivault          #+#    #+#             */
/*   Updated: 2026/07/13 08:00:57 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	print_action(char *str, t_philo *philo)
{
	long	time;

	if (check_sim_stop(philo->table))
		return ;
	pthread_mutex_lock(&philo->table->write_mutex);
	if (check_sim_stop(philo->table))
	{
		pthread_mutex_unlock(&philo->table->write_mutex);
		return ;
	}
	time = get_current_time() - philo->table->start_time;
	printf("%ld %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->table->write_mutex);
}
