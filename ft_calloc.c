/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 21:05:10 by arasal            #+#    #+#             */
/*   Updated: 2022/05/05 00:12:29 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*The calloc() function contiguously allocates enough space for count 
objects that are size bytes of memory each and returns a pointer to 
the allocated memory. The allocated memory is filled with bytes of 
value zero.*/
char	*ft_calloc(int count, char c)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(count + 1);
	if (str == NULL)
		return (NULL);
	while (i < count)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
