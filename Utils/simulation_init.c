/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:36:59 by grivault          #+#    #+#             */
/*   Updated: 2026/07/20 18:55:02 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	simulation_init(t_table *table, t_philo *philos, int ac, char **argv)
{
	if (!table_init(ac, argv, table))
		return (1);
	printf("table_init done");
	*philos = philosophers_init(table);
	if (!philos)
		return (table_cleanup(table), 1);
	printf("philosopher_init done");
	return (0);
}
