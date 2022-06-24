/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:10:09 by arasal            #+#    #+#             */
/*   Updated: 2022/05/05 21:52:11 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Allocates (with malloc(3)) and returns a new string, which is the result
of the concatenation of ’s1’ and ’s2’. Returns the new string or NULL if 
the allocation fails.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	int		s3len;
	char	*s3;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	s3len = 0;
	s3 = (char *)malloc(s1len + s2len + 1);
	if (!s3)
		return (0);
	while (s3len < s1len + s2len)
	{
		if (s3len < s1len)
			s3[s3len] = s1[s3len];
		else
			s3[s3len] = s2[s3len - s1len];
		s3len++;
	}
	s3[s3len] = '\0';
	free((void *)s1);
	free((void *)s2);
	return (s3);
}
