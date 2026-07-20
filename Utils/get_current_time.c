/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 21:33:08 by grivault          #+#    #+#             */
/*   Updated: 2026/07/20 20:26:56 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (put_error(ERROR_GETTIMEOFDAY_FAILED), -1);
	return (SEC_TO_MS(time.tv_sec) + MICRO_TO_MS(time.tv_usec));
}
