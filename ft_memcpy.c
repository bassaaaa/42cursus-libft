/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:30:38 by tsito             #+#    #+#             */
/*   Updated: 2026/04/14 21:46:48 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;

	d_ptr = dst;
	s_ptr = src;
	while (n--)
		*d_ptr++ = *s_ptr++;
	return (dst);
}
