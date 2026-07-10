/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 22:25:13 by grivault          #+#    #+#             */
/*   Updated: 2026/07/10 22:37:52 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	put_error_mutex_lock(char *error_str, t_table *table)
{
	pthread_mutex_lock(&table->write_mutex);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_str, 2);
	pthread_mutex_unlock(&table->write_mutex);
}

void	put_error(char *error_str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_str, 2);
}
