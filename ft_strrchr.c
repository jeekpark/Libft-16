/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:43:21 by jeekpark          #+#    #+#             */
/*   Updated: 2024/04/18 19:33:05 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	char	ch;

	ch = (char)c;

	save = NULL;
	while (1)
		{
			if (*s == ch)
				save = (char *)s;
			if (*s == '\0')
				return (save);
		}
	return (NULL);
}
