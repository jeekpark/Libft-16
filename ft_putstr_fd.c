/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:29:44 by jeekpark          #+#    #+#             */
/*   Updated: 2024/04/18 19:07:00 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	left_len;
	size_t	target_len;
	ssize_t	wrote;

	left_len = ft_strlen(s);
	while (left_len)
	{
		target_len = left_len;
		if (target_len > SSIZE_MAX)
			target_len = SSIZE_MAX;
		wrote = write(fd, s, target_len);
		if (wrote < 0)
			return ;
		left_len -= (size_t) wrote;
		s += wrote;
	}
}
