/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_time.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 21:33:08 by grivault          #+#    #+#             */
/*   Updated: 2026/07/10 21:39:36 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1) // rechercher autres params de func
	{
		return (-1); // a gerer l'erreur gettimeofday failed
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
