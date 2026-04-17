/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:16:32 by tsito             #+#    #+#             */
/*   Updated: 2026/04/17 14:03:30 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_elem)
{
	t_list	*last;

	if (!lst || !new_elem)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		*lst = new_elem;
	else
		last->next = new_elem;
}
