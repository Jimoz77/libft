/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiparcer <jiparcer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:13:01 by jiparcer          #+#    #+#             */
/*   Updated: 2024/10/09 14:13:18 by jiparcer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	int 			i;

	source = s;
	i = 0;
	while (i < n)
	{
		if (source[i] == (unsigned char)c)
		{
			return (s);
		}
		i++;
		s++;
	}
	return (NULL);
}
