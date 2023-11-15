

#include "get_next_line.h"

static int	read_line(char **ret, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	if (gk_strchr(*ret, '\n'))
		return (0);
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (1);
		if (bytes_read == 0)
			return (0);
		buffer[bytes_read] = '\0';
		if (gk_strjoin(ret, buffer))
			return (1);
		if (gk_strchr(*ret, '\n'))
			return (0);
	}
	return (0);
}

static int	cut_line(char **mem, char **ret)
{
	int		pos;

	if (!(*ret))
		return (0);
	pos = gk_strlen(*ret, '\n');
	if ((*ret)[pos] == '\0')
		return (0);
	*mem = malloc((gk_strlen(&(*ret)[pos], '\0')) * sizeof(char));
	if (!(*mem))
		return (free(*ret), 1);
	gk_strcpy(*mem, &(*ret)[pos + 1]);
	(*ret)[pos + 1] = '\0';
	if (gk_strjoin(ret, NULL))
		return (free(*ret), 1);
	return (0);
}

void	mynull(void **s)
{
	if (*s)
	{
		free(*s);
		*s = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*mem = NULL;
	char		test[1];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE > 2147483647
		|| BUFFER_SIZE < 1 || read(fd, test, 0) == -1)
	{
		if (mem)
			free(mem);
		mem = NULL;
		return (NULL);
	}
	ret = NULL;
	if (mem)
	{
		ret = mem;
		mem = NULL;
	}
	if (read_line(&ret, fd))
		return (free(ret), NULL);
	if (cut_line(&mem, &ret))
		return (NULL);
	if (gk_strlen(ret, '\0') == 0)
		mynull((void **)&ret);
	return (ret);
}
