/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:28:22 by grivault          #+#    #+#             */
/*   Updated: 2026/07/10 19:55:52 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_table {
    int             num_philos;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             max_meals;      // Optional argument
    
    long            start_time;     // When the simulation started
    int             sim_stop;       // Flag set to 1 if someone dies or everyone is full
    
    pthread_mutex_t write_mutex;    // Prevents print messages from overlapping
    pthread_mutex_t sync_mutex;     // Protects shared variables like 'sim_stop'
    pthread_mutex_t *forks;         // Array of fork mutexes
} t_table;

typedef struct s_philo {
    int             id;             // Philosopher ID (1 to num_philos)
    long            last_meal_time; // Timestamp of the last meal
    int             meals_eaten;    // Counter for the optional argument

    pthread_t       thread_id;      // The thread representing this philosopher

	pthread_mutex_t meal_mutex;
    pthread_mutex_t *left_fork;     // Pointer to their own fork
    pthread_mutex_t *right_fork;    // Pointer to their neighbor's fork

    t_table         *table;         // Pointer to the master structure
} t_philo;
