/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:13:24 by arasal            #+#    #+#             */
/*   Updated: 2022/05/05 19:14:26 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*The atoi function works by removing all possible whitespace 
characters similar to the isspace function—until it encounters 
the first non-whitespace character. After the first non-whitespace, 
it assigns an optional sign (positive or negative). Next, it 
parses all the possible base-10 values until it encounters a 
non-numerical character. This could be a null-terminating character. 
Finally, it interprets the values into their corresponding integer type.*/
int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	j;

	res = 0;
	i = 0;
	j = 1;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * j);
}
