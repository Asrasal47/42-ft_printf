/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:47:51 by arasal            #+#    #+#             */
/*   Updated: 2022/05/05 21:49:45 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*The strlen() function computes the length of the string s. The strnlen() 
function attempts to compute the length of s, but never scans beyond the 
first maxlen bytes of s.*/
int	ft_strlen(const char *s)
{
	int	t;

	t = 0;
	if (s == NULL)
		return (0);
	while (s[t] != '\0')
		t++;
	return (t);
}
