/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:33:46 by jeekpark          #+#    #+#             */
/*   Updated: 2022/11/11 17:55:27 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*tmp;

	if (lst == (void *) 0)
		return (0);
	res = 1;
	tmp = lst;
	while (tmp->next)
	{
		res++;
		tmp = tmp->next;
	}
	return (res);
}
