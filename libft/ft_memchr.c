#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*source;
	int 			i;

	source = s;
	i = 0;
	while (source[i] && i < n)
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