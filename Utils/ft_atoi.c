/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 19:22:16 by grivault          #+#    #+#             */
/*   Updated: 2026/07/12 18:42:26 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_strlen_nbr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] && (s[i] >= 48) && (s[i] <= 57))
		i++;
	return (i);
}

static	int	ft_sign(char c)
{
	if (c == '-')
		return (-1);
	if (c == '+')
		return (1);
	return (0);
}

static int	ft_skip_blanks(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	unit;
	int	i;
	int	total;
	int	sign;

	str += ft_skip_blanks(str);
	sign = 1;
	total = 0;
	unit = 1;
	i = ft_strlen_nbr(str) - 1;
	if (i < 0 || !str)
		return (0);
	while (i >= 0)
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			sign = ft_sign(str[i--]);
		else
		{
			total += (unit * ((str[i]) - 48));
			unit *= 10;
			i--;
		}
	}
	return (total * sign);
}
