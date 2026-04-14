/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:12:10 by tsito             #+#    #+#             */
/*   Updated: 2026/04/14 22:01:04 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		sign;
	long	result;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	result = 0;
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return ((int)(sign * result));
}
