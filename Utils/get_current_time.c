/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 21:33:08 by grivault          #+#    #+#             */
/*   Updated: 2026/07/15 16:26:02 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1) // rechercher autres params de func
		return (put_error(ERROR_GETTIMEOFDAY_FAILED), -1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
