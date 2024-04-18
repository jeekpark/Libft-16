/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:55:36 by jeekpark          #+#    #+#             */
/*   Updated: 2022/11/11 18:06:10 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*res;

	res = lst;
	if (res == (void *) 0)
		return (res);
	while (res->next)
	{
		if (res->next->next == (void *) 0)
			return (res->next);
		res = res->next;
	}
	return (res);
}
