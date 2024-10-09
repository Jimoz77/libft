#include "libft.h"

static void free_all(char **result, int words)
{
    for (int i = 0; i < words; i++)
        free(result[i]);
    free(result);
}
static int count_words(char *str, char c)
{
	int in_word;
	int count;

	count = 0;
	in_word = 0;
	while(*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if(*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}
static char *malloc_word(const char *str, char c)
{
	char *word;
	int len;
	int i;

    len = 0;
	i = 0;
    while (str[len] && str[len] != c)
        len++;
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;
    while (i < len)
	{
        word[i] = str[i];
		i++;
	}
    word[len] = '\0';
    return word;
}

char **ft_split(char const *s, char c)
{
	int words;
	int i;
	char **result;

	i = 0;
	words = count_words(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
	{
		return (NULL);
	}
	if(!s)
	{
		return (NULL);
	}
	
	while (*s) // malloc de toutes les chaines
	{
		if (*s != c)
		{
			result[i] = malloc_word(s, c);
			if(!result[i])
			{
				free_all(result, i);
				return (NULL);
			}
			i++;
			while(*s && *s != c)
			{
				s++;
			}
		}
		else
			s++;
	}
	result[i] = NULL;
	return result;
}