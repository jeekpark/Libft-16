/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeekpark <jeekpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:23:15 by jeekpark          #+#    #+#             */
/*   Updated: 2024/04/18 20:19:28 by jeekpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	get_long_limit(int is_negative)
{
	if (is_negative)
		return (LONG_MIN);
	else
		return (LONG_MAX);
}

static int is_int_overflow(size_t sum, int num, int is_negative)
{
	size_t next_sum;
	size_t int_max;
	size_t int_min;

	int_max = INT_MAX;
	int_min = int_max + 1;
	next_sum = sum * 10 + num;
	if (is_negative && next_sum > int_min)
		return (1);
	else if (is_negative == 0 && next_sum > int_max)
		return (1);
	else
		return (0);
}

int ft_atoi(const char *str)
{
	size_t	sum;
	int		is_negative;

	sum = 0;
	is_negative = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			is_negative = 1;
	}
	while ('0' <= *str && *str <= '9')
	{
		if (is_int_overflow(sum, *str - '0', is_negative))
			return ((int)get_long_limit(is_negative));
		sum = sum * 10 + *str++ - '0';
	}
	if (is_negative)
		return ((int)((long)sum * -1));
    return ((int)sum);
}
