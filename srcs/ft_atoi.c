/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsiffre <chsiffre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:18:10 by charles           #+#    #+#             */
/*   Updated: 2023/02/28 15:33:30 by chsiffre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long long int	ft_conv(long long int res)
{
	if (res > INT_MAX)
		return (res - LLONG_MAX - 1);
	else if (res < INT_MIN)
		return (res - LLONG_MIN);
	else
		return (res);
}

static long long	ft_check(char str, long long res, int sign)
{
	if ((res * 10 + (str - '0')) * sign < -2147483648)
		return (2147483648);
	if ((res * 10 + (str - '0')) * sign >= 2147483648)
		return (2147483648);
	return (0);
}

long long	ft_atoi(const char	*str)
{
	int				count;
	long long int	res;
	int				sign;

	count = 0;
	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while ((*str == '-' || *str == '+') && ++count)
	{	
		if (*str == '-')
			sign *= -1;
		if (count > 1)
			return (2147483648);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (ft_check(*str, res, sign) == 2147483648)
			return (2147483648);
		res = (res * 10) + *str - '0';
		str++;
	}
	return ((int) ft_conv(res * sign));
}
