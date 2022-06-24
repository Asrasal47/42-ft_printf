/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:31:43 by arasal            #+#    #+#             */
/*   Updated: 2022/05/08 13:14:44 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_fd(unsigned int nbr, char c)
{
	int	len;

	len = 0;
	if (nbr < 10)
		len += ft_putchar_fd(nbr + 48);
	else if (nbr < 16)
	{
		if (c == 'x')
			len += ft_putchar_fd(nbr + 87);
		if (c == 'X')
			len += ft_putchar_fd(nbr + 55);
	}
	else
	{
		len += ft_putnbr_hex_fd(nbr / 16, c);
		len += ft_putnbr_hex_fd(nbr % 16, c);
	}
	return (len);
}

int	ft_putnbr_hex_prec(unsigned int nbr, t_flags f)
{
	char	*prec;
	int		len;	

	len = 0;
	prec = NULL;
	if (ft_putnbr_hex_counter(nbr) < f.precision)
	{
		prec = ft_calloc(f.precision - ft_putnbr_hex_counter(nbr), '0');
		len += ft_putstr_fd(prec);
	}
	free (prec);
	return (len);
}

void	ft_putnbr_hex_norm(unsigned int nbr, char c, t_flags *f)
{
	f->len = 0;
	f->ch = ' ';
	f->s = NULL;
	f->h = NULL;
	if (f->zero == 1)
		f->ch = '0';
	if (f->precision == 0 && nbr == 0 && f->width > 0)
		f->width += 1;
	f->len = ft_putnbr_hex_counter(nbr);
	if (f->hash == 1 && nbr != 0)
	{
		f->h = (char *)malloc(3);
		f->h[0] = '0';
		f->h[1] = c;
		f->h[2] = '\0';
		f->len += 2;
	}
	if (f->width > f->len && f->precision > 0 && f->hash == 1 && nbr != 0)
		f->s = ft_calloc(f->width - f->precision - 2, f->ch);
	else if (f->width > f->len && f->precision >= f->len)
		f->s = ft_calloc(f->width - f->precision, f->ch);
	else if ((f->width > f->len) && f->precision < f->len)
		f->s = ft_calloc(f->width - f->len, f->ch);
	f->len = 0;
}

int	ft_putnbr_hex(unsigned int nbr, char c, t_flags f)
{
	if (f.precision >= 0)
		f.zero = 0;
	ft_putnbr_hex_norm(nbr, c, &f);
	if (f.minus == 1)
	{
		f.len += ft_putstr_fd(f.h);
		f.len += ft_putnbr_hex_prec(nbr, f);
		if (!(f.precision == 0 && nbr == 0))
			f.len += ft_putnbr_hex_fd(nbr, c);
		f.len += ft_putstr_fd(f.s);
	}
	else
	{
		f.len += ft_putstr_fd(f.s);
		f.len += ft_putstr_fd(f.h);
		f.len += ft_putnbr_hex_prec(nbr, f);
		if (!(f.precision == 0 && nbr == 0))
			f.len += ft_putnbr_hex_fd(nbr, c);
	}
	free (f.s);
	free (f.h);
	return (f.len);
}

int	ft_putnbr_hex_counter(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr < 10)
		len += 1;
	else if (nbr < 16)
		len += 1;
	else
	{
		len += ft_putnbr_hex_counter(nbr / 16);
		len += ft_putnbr_hex_counter(nbr % 16);
	}
	return (len);
}
