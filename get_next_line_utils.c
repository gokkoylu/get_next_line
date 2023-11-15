

#include "get_next_line.h"

size_t	gk_strlen(char *s, int delim)
{
	size_t	ret;

	ret = 0;
	if (!s)
		return (0);
	while (s[ret] != (char)delim)
	{
		if (!s[ret])
			return (ret);
		ret++;
	}
	return (ret);
}

int	gk_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*gk_strchr(char *s, int delim)
{
	if (!s)
		return (0);
	while (*s != (char)delim)
		if (!*s++)
			return (0);
	return ((char *)s);
}

int	gk_strjoin(char **dst, char *src)
{
	char	*new;
	int		len;

	len = 0;
	if ((*dst))
		len = gk_strlen(*dst, '\0');
	len += gk_strlen(src, '\0');
	new = malloc((len + 1) * sizeof(char));
	if (!new)
		return (1);
	new[len] = '\0';
	gk_strcpy(&new[gk_strcpy(new, *dst)], src);
	free(*dst);
	*dst = new;
	return (0);
}
