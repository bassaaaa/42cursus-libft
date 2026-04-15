/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:30:07 by tsito             #+#    #+#             */
/*   Updated: 2026/04/15 23:44:12 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;

	d_ptr = (unsigned char *)dst;
	s_ptr = (unsigned char *)src;
	if (s_ptr < d_ptr && d_ptr < s_ptr + len)
	{
		d_ptr += len;
		s_ptr += len;
		while (len--)
			*--d_ptr = *--s_ptr;
	}
	else
	{
		while (len--)
			*d_ptr++ = *s_ptr++;
	}
	return (dst);
}
