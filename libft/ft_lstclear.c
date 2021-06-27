/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrex <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:28:21 by akrex             #+#    #+#             */
/*   Updated: 2020/11/21 19:28:57 by akrex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;

	new = *lst;
	if (lst == NULL)
		return ;
	if (del)
	{
		while (new)
		{
			del(new->content);
			free(new);
			new = new->next;
		}
	}
	*lst = NULL;
}
