#include <stdlib.h>
static int			wordcounter(char *str);
static char			*next_valid_char(char *str);
static char			*next_whitespace(char *str);
static void			lenstrcopy(char *s1, char *s2, int len);

char	**ft_split(char *str)
{
	int		index;
	int		wordcount;
	char	*start;
	char	*end;
	char	**split;

	index = -1;
	wordcount = wordcounter(str);
	split = malloc(sizeof(char *) * (wordcount + 1));
	split[wordcount] = NULL;
	while (++index < wordcount)
	{
		start = next_valid_char(str);
		end = next_whitespace(start);
		split[index] = malloc(sizeof(char) * (end - start + 1));
		lenstrcopy(split[index], start, end - start);
		str = end;
	}
	return (split);
}

static inline int	wordcounter(char *str)
{
	int	words;
	int	inside_word;

	words = 0;
	inside_word = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			inside_word = 0;
		else if (!inside_word)
		{
			words++;
			inside_word = 1;
		}
		str++;
	}
	return (words);
}

static inline void	lenstrcopy(char *s1, char *s2, int len)
{
	while (len--)
		*s1++ = *s2++;
	*s1 = '\0';
}

static inline char	*next_valid_char(char *str)
{
	while (*str == ' ' || *str == '\t' || '\0')
		str++;
	return (str);
}

static inline char	*next_whitespace(char *c)
{
	while (*c != ' ' && *c != '\t' && *c != '\0')
		c++;
	return (c);
}
