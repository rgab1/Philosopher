/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 20:13:08 by grivault          #+#    #+#             */
/*   Updated: 2026/07/20 20:52:35 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// get_current_time
# define SEC_TO_MS(sec) ((sec) * 1000)
# define MICRO_TO_US(sec)  ((ms) * 1000)

// philo_routine
# define STAGGER(id, eat) (((id) % 2) * ((eat) / 2))

#endif
