/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:47:49 by arasal            #+#    #+#             */
/*   Updated: 2022/05/10 13:54:00 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printconversions(const char **s, va_list args, t_flags f)
{
	int	len;

	len = 0;
	if (**s == 'c')
		len += ft_putchar((char)va_arg(args, int), f);
	else if (**s == 's')
		len += ft_putstr(va_arg(args, char *), f);
	else if (**s == 'p')
		len += ft_putadd(va_arg(args, unsigned long), f);
	else if (**s == 'd' || **s == 'i')
		len += ft_putnbr(va_arg(args, int), f);
	else if (**s == 'u')
		len += ft_putnbr_unsigned(va_arg(args, unsigned long long), f);
	else if (**s == 'x' || **s == 'X')
		len += ft_putnbr_hex(va_arg(args, unsigned int), **s, f);
	else if (**s == '%')
		len += ft_putchar('%', f);
	(*s)++;
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	args;
	t_flags	f;

	len = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			f = ft_flags(&s);
			if (ft_strchr("disuxXcp%", *s))
				len += ft_printconversions(&s, args, f);
		}
		else
		{
			len += ft_putchar_fd(*s);
			s++;
		}
	}
	va_end(args);
	return (len);
}

int main(void)
{
	int a = ft_printf("%464");
	int b = printf("%546");
	printf("%d", a);
	printf("%d", b);
	return (0);
}