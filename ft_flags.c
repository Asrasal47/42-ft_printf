/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:58:12 by arasal            #+#    #+#             */
/*   Updated: 2022/05/08 05:35:52 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flagsinit(void)
{
	t_flags	f;

	f.plus = 0;
	f.space = 0;
	f.zero = 0;
	f.minus = 0;
	f.hash = 0;
	f.width = 0;
	f.precision = -1;
	return (f);
}

void	ft_flagscheck(t_flags *f)
{
	if (f->minus == 1)
		f->zero = 0;
	if (f->plus == 1)
		f->space = 0;
	if (f->width == 0)
		f->minus = 0;
	if (f->width == 0)
		f->zero = 0;
}

int	ft_atoi_plus(const char *s, t_flags *set)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	set->width = res;
	return (i - 1);
}

int	ft_precision(const char *s, t_flags *set)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	set->precision = res;
	return (i - 1);
}

t_flags	ft_flags(const char **s)
{
	t_flags	set;

	set = ft_flagsinit();
	while (ft_strchr("+ 0-#.123456789", **s))
	{
		if (**s == '+')
			set.plus = 1;
		else if (**s == ' ')
			set.space = 1;
		else if (**s == '0')
			set.zero = 1;
		else if (**s == '-')
			set.minus = 1;
		else if (**s == '#')
			set.hash = 1;
		else if (**s > 48 && **s < 58)
			(*s) += ft_atoi_plus(*s, &set);
		else if (**s == '.')
			(*s) += ft_precision(*s, &set);
		(*s)++;
	}
	ft_flagscheck(&set);
	return (set);
}
