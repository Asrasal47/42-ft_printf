/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alphabets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 14:30:59 by arasal            #+#    #+#             */
/*   Updated: 2022/05/08 02:06:02 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags f)
{
	char	*s;
	int		len;
	char	ch;

	s = NULL;
	len = 0;
	ch = ' ';
	if (c == '%' && f.zero == 1)
		ch = '0';
	if (f.width > 1 && f.minus == 0)
	{
		s = ft_calloc(f.width - 1, ch);
		len += ft_putstr_fd(s);
		len += ft_putchar_fd(c);
	}
	else if (f.width > 1 && f.minus == 1)
	{
		s = ft_calloc(f.width - 1, ch);
		len += ft_putchar_fd(c);
		len += ft_putstr_fd(s);
	}
	else
		len += ft_putchar_fd(c);
	free (s);
	return (len);
}

int	ft_putchar_fd(char c)
{
	write(1, &c, 1);
	return (1);
}

int	quick_fix(const char *s, t_flags f)
{
	int	len;

	len = 0;
	while (s && *s && f.precision == -1)
	{
		write(1, s, 1);
		s++;
		len++;
	}
	while (s && *s && f.precision >= 0 && (len < f.precision))
	{
		write(1, s, 1);
		s++;
		len++;
	}
	return (len);
}

int	ft_putstr(const char *s, t_flags f)
{
	int		len;

	len = 0;
	if (s == NULL)
	{
		len += ft_putstr("(null)", f);
		return (len);
	}
	if (f.precision > ft_strlen(s) || f.precision == -1)
		f.precision = ft_strlen(s);
	if (f.minus == 1)
	{
		len += quick_fix(s, f);
		while (f.width-- > f.precision)
			len += ft_putchar_fd(' ');
	}
	else
	{
		while (f.width-- > f.precision)
			len += ft_putchar_fd(' ');
		len += quick_fix(s, f);
	}
	return (len);
}
