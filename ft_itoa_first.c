/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:55:38 by arasal            #+#    #+#             */
/*   Updated: 2022/05/08 13:10:31 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_f(int sign, char *str, long long n, t_flags f)
{
	if (sign > 0 && f.precision <= f.width && f.plus == 1
		&& f.precision < ft_strlen(str) && f.width > ft_strlen(str))
		str[0] = '+';
	if (sign > 0 && f.precision <= f.width && f.space == 1
		&& f.precision < ft_strlen(str) && f.width > ft_strlen(str))
		str[0] = ' ';
	if (sign > 0 && f.precision > f.width && (f.plus == 1 || f.space == 1))
		str[0] = n + '0';
	else if (sign > 0 && f.plus == 1 && f.zero == 0 && f.precision < 0)
		str[0] = '+';
	else if (sign > 0 && f.space == 1 && f.zero == 0 && f.precision < 0)
		str[0] = ' ';
	else if (sign > 0 && f.plus == 1 && f.precision < ft_strlen(str))
		str[0] = '+';
	else if (sign > 0 && f.space == 1 && f.precision < ft_strlen(str))
		str[0] = ' ';
	else if (sign > 0 && f.width == 0 && f.zero == 1)
		str[0] = '0';
	else if (sign < 0 && f.zero == 0)
		str[0] = '-';
	else
		str[0] = n + '0';
}
