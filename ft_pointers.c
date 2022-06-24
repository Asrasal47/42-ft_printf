/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:53:00 by arasal            #+#    #+#             */
/*   Updated: 2022/05/06 02:53:48 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd_fd(unsigned long add)
{
	int	len;

	len = 0;
	if (add < 10)
		len += ft_putchar_fd(add + 48);
	else if (add < 16)
		len += ft_putchar_fd(add + 87);
	else
	{
		len += ft_putadd_fd(add / 16);
		len += ft_putadd_fd(add % 16);
	}
	return (len);
}

void	ft_putadd_norm(int *len, unsigned long add, char **s, t_flags *f)
{
	if (f->minus == 1)
	{
		*len += ft_putstr_fd("0x");
		if (!(f->precision == 0 && add == 0))
			*len += ft_putadd_fd(add);
		*len += ft_putstr_fd(*s);
	}
	else
	{
		*len += ft_putstr_fd(*s);
		*len += ft_putstr_fd("0x");
		if (!(f->precision == 0 && add == 0))
			*len += ft_putadd_fd(add);
	}
}

int	ft_putadd(unsigned long add, t_flags f)
{
	int				len;
	char			ch;
	char			*s;

	len = 2;
	ch = ' ';
	s = NULL;
	if (f.precision == 0 && add == 0 && f.width > 0)
		f.width += 1;
	len += ft_putnbr_hex_counter(add);
	if (f.width > len)
		s = ft_calloc(f.width - len, ch);
	len = 0;
	ft_putadd_norm(&len, add, &s, &f);
	free (s);
	return (len);
}
