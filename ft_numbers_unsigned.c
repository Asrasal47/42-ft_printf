/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 02:47:47 by arasal            #+#    #+#             */
/*   Updated: 2022/05/07 01:14:20 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setstr_u(char *str, t_flags f, unsigned long long n)
{
	char		*temp;
	char		*prec;
	char		c;

	c = ' ';
	if (f.zero == 1 && f.minus != 1)
		c = '0';
	str = ft_itoa(n, f);
	if (n == 0 && f.precision == 0)
		str = NULL;
	if (ft_strlen(str) < f.precision)
	{
		prec = ft_calloc(f.precision - ft_strlen(str), '0');
		str = ft_strjoin(prec, str);
	}
	if ((ft_strlen(str) < f.width))
	{
		temp = ft_calloc(f.width - ft_strlen(str), c);
		if (f.minus == 1)
			str = ft_strjoin(str, temp);
		else
			str = ft_strjoin(temp, str);
	}
	return (str);
}

int	ft_putnbr_unsigned(unsigned int nbr, t_flags f)
{
	int					len;
	char				*str;
	unsigned long long	n;

	n = 0;
	len = 0;
	str = NULL;
	if (f.precision >= 0)
		f.zero = 0;
	if (f.plus == 1)
		f.plus = 0;
	n = nbr;
	str = ft_setstr_u(str, f, n);
	if (f.plus == 1 && f.zero == 1)
		str[0] = '+';
	else if (f.space == 1 && f.zero == 1)
		str[0] = ' ';
	len += ft_putstr_fd(str);
	free (str);
	return (len);
}
