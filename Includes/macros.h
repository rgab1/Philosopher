/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 20:13:08 by grivault          #+#    #+#             */
/*   Updated: 2026/07/20 20:26:52 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

// get_current_time
# define SEC_TO_MS(sec) ((sec) * 1000)
# define MICRO_TO_US(sec)  ((ms) * 1000)

# define STAGGER(id, eat) (((id) % 2) * ((eat) / 2))

# define ODD_THINK(die, eat, sleep) (((die) - ((eat) + (sleep))) / 2)

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define STEP_THRESHOLD 10
#define SLEEP_LONG_US 1000
#define SLEEP_SHORT_US 100


#endif
