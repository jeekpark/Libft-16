/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:52:29 by jeekpark          #+#    #+#             */
/*   Updated: 2022/11/14 17:18:06 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstputcontent(t_list **res, void *content)
{
		(*res)->content = content;
		(*res)->next = 0;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_f;
	t_list	*res;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	res = (t_list *) malloc(sizeof(t_list));
	if (res == (void *) 0)
		return ((void *) 0);
	ft_lstputcontent(&res, f(lst->content));
	lst_f = res;
	lst = lst->next;
	while (lst)
	{
		lst_f->next = (t_list *) malloc(sizeof(t_list));
		if (lst_f->next == 0)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		lst_f = lst_f->next;
		ft_lstputcontent(&lst_f, f(lst->content));
		lst = lst->next;
	}
	return (res);
}
