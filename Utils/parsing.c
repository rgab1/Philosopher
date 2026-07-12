/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 16:28:48 by grivault          #+#    #+#             */
/*   Updated: 2026/07/12 18:38:09 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

static int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

static int	table_value_assignation(char **av, t_table *table)
{
	int	i;

	i = 0
	table->num_philos = ft_atoi(av[i++]); // a tester que la fonction atoi gere bien plusieurs +/-
	table->time_to_die = ft_atoi(av[i++]);
	table->time_to_eat = ft_atoi(av[i++]);
	table->time_to_sleep = ft_atoi(av[i++]);
	if (av[i])
		table->max_meals = ft_atoi(av[i]);
	if (table->num_philos < 0 || table->time_to_die < 0 ||
			table->time_to_eat < 0 ||table->time_to_sleep < 0 ||
			table->max_meals < 0)
		return (put_error(ERROR_ARGS_POSITVE_NBR), 1);
	return (0);
}

int	parsing(int ac, char **av, t_table *table)
{
	int	i;
	int	j;

	i = 0;
	if (ac < 4 || ac > 5 )
		return (put_error(ERROR_EXPECTED_NBR_ARGS), 1);
	while (av[i])
	{
		j = 0;
		while (av[i][j] == '+' || av[i][j] == '-')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j++]))
				return (put_error(ERROR_ARGS_POSITVE_NBR), 1);
		}
		i++;
	}
	return (table_value_assignation(av, table));
}
