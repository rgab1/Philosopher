/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 04:58:52 by grivault          #+#    #+#             */
/*   Updated: 2026/07/14 05:39:41 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef ROUTINE_H
# define ROUTINE_H

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

int		check_sim_stop(t_table *table);
void	smart_sleep(long sleep_time, t_table *table);
void	print_action(char *str, t_philo *philo);
void	philo_eat(t_philo *philo);

void	monitor_routine(t_philo *philos);
void	*philosopher_routine(void *arg);

#endif
