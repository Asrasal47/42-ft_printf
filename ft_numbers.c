/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:46:37 by arasal            #+#    #+#             */
/*   Updated: 2022/05/08 13:05:51 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_setstr_norm(int nbr, char **s, t_flags *f)
{
	char	*prec;

	prec = NULL;
	if (ft_strlen(*s) < f->precision)
	{
		prec = ft_calloc(f->precision - ft_strlen(*s), '0');
		*s = ft_strjoin(prec, *s);
		if (nbr < 0)
			*s[0] = '-';
	}
	else if (f->precision > 0 && nbr < 0)
	{
		prec = ft_calloc(1, '-');
		*s = ft_strjoin(prec, *s);
	}
	return (*s);
}

char	*ft_setstr(t_flags f, int nbr, int len, long long n)
{
	char		*temp;
	char		*prec;
	char		*str;

	f.ch = ' ';
	if (f.zero == 1 && f.minus != 1)
		f.ch = '0';
	str = ft_itoa(n, f);
	if (n == 0 && f.precision == 0)
		str = NULL;
	prec = ft_setstr_norm(nbr, &str, &f);
	if ((ft_strlen(str) + len < f.width))
	{
		temp = ft_calloc(f.width - ft_strlen(str) - len, f.ch);
		if (f.precision > 0 && f.precision < f.width && f.plus == 1
			&& f.minus == 0 && f.precision > ft_strlen(str) - 1)
			temp[ft_strlen(temp) - 1] = '+';
		if (f.precision > 0 && f.precision < f.width && f.space == 1)
			temp[ft_strlen(temp) - 1] = ' ';
		if (f.minus == 1)
			str = ft_strjoin(str, temp);
		else
			str = ft_strjoin(temp, str);
	}
	return (str);
}

long long	ft_putnbr_norm(int nbr, int *len, t_flags *f)
{
	long long	n;
	char		c;

	c = ' ';
	if (f->plus == 1)
		c = '+';
	if (f->precision >= 0)
		f->zero = 0;
	if ((nbr < 0 && f->zero == 1) || (nbr < 0 && f->precision >= 1))
	{
		if (f->zero == 1)
			*len += ft_putchar_fd('-');
		if (f->precision >= 1)
			f->precision += 1;
		n = nbr;
		n *= -1;
	}
	else if (f->precision > f->width && (f->plus == 1 || f-> space == 1))
	{
		*len += ft_putchar_fd(c);
		n = nbr;
	}
	else
		n = nbr;
	return (n);
}

int	ft_putnbr(int nbr, t_flags f)
{
	int			len;
	char		*str;
	long long	n;

	if (nbr < 0)
	{
		f.plus = 0;
		f.space = 0;
	}
	len = 0;
	n = ft_putnbr_norm(nbr, &len, &f);
	if (f.precision > 0 && f.precision < f.width && f.space == 1
		&& nbr == 0 && f.minus == 1)
		len += ft_putchar_fd(' ');
	else if (f.precision > 0 && f.precision < f.width && f.plus == 1
		&& nbr == 0 && f.minus == 1)
		len += ft_putchar_fd('+');
	str = ft_setstr(f, nbr, len, n);
	if (n >= 0 && f.plus == 1 & f.zero == 1)
		str[0] = '+';
	else if (n >= 0 && f.space == 1 && f.zero == 1)
		str[0] = ' ';
	len += ft_putstr_fd(str);
	free (str);
	return (len);
}
