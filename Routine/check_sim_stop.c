/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sim_stop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 05:43:44 by grivault          #+#    #+#             */
/*   Updated: 2026/07/13 05:45:54 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	check_sim_stop(t_table *table)
{
	int	status;

	pthread_mutex_lock(&table->sync_mutex);
	status = table->sim_stop;
	pthread_mutex_unlock(&table->sync_mutex);
	return (status);
}
