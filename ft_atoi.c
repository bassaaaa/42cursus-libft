/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 22:12:10 by tsito             #+#    #+#             */
/*   Updated: 2026/04/15 16:28:07 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_to_int(int sign, unsigned long result)
{
	if (sign > 0 && result > (unsigned long)LONG_MAX)
		return ((int)LONG_MAX);
	if (sign < 0 && result > (unsigned long)LONG_MAX + 1)
		return ((int)LONG_MIN);
	return ((int)((long)result * sign));
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned long	result;

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
		if (result > (ULONG_MAX - (unsigned long)(*str - '0')) / 10)
			result = ULONG_MAX;
		else
			result = result * 10 + (unsigned long)(*str - '0');
		str++;
	}
	return (convert_to_int(sign, result));
}
