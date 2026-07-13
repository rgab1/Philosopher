/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 04:45:53 by grivault          #+#    #+#             */
/*   Updated: 2026/07/13 04:50:03 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	smart_sleep(long sleep_time, t_table *table)
{
	long	start_time;

	start_time = get_current_time(void);
	while ((get_current_time() - start_time) < sleep_time)
	{
		if (check_sim_stop(table))
			break ;
		usleep(500);
	}
}
