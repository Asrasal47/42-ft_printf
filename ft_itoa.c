/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:14:20 by arasal            #+#    #+#             */
/*   Updated: 2022/05/08 13:13:53 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Allocates (with malloc(3)) and returns a string representing the integer 
received as an argument. Negative numbers must be handled. It returns
the string representing the integer or NULL if the allocation fails.*/
static int	ft_sign(long long n)
{
	int	si;

	si = 1;
	if (n < 0)
	{
		si = -1;
	}
	return (si);
}

static int	ft_counter(long long n, t_flags f)
{
	int			k;
	long long	nbr;

	k = 0;
	nbr = n;
	while (nbr != 0 && k++ >= 0)
		nbr = nbr / 10;
	if (n == 0 && f.space == 0 && f.plus == 0 && f.zero == 0)
		k += 1;
	else if (n == 0 && f.space == 0 && f.plus == 0 && f.zero == 1)
		k += 1;
	else if (n == 0 && (f.space == 1 || f.plus == 1)
		&& f.zero == 0 && f.precision < 0)
		k += 2;
	else if (n > 0 && (f.space == 1 || f.plus == 1)
		&& f.precision <= k && f.width < f.precision)
		k += 0;
	else if (n > 0 && (f.space == 1 || f.plus == 1)
		&& f.precision > k && f.width > f.precision)
		k += 2;
	else if (n > 0 && (f.space == 1 || f.plus == 1))
		k += 1;
	else if (n < 0 && f.zero == 0)
		k += 1;
	return (k);
}

char	*ft_itoa(long long n, t_flags f)
{
	char		*str;
	int			i;
	int			sign;

	sign = ft_sign(n);
	i = ft_counter(n, f);
	if (sign < 0)
		n = -n;
	str = (char *)malloc(i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	while (i - 1 > 0)
	{
		str[i-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	ft_itoa_f(sign, &str[i - 1], n, f);
	return (str);
}
