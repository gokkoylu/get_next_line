
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  41
# endif
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

// utils
size_t	gk_strlen(char *s, int delim);
int		gk_strcpy(char *dst, char *src);
char	*gk_strchr(char *s, int delim);
int		gk_strjoin(char **dst, char *src);
// main
char	*get_next_line(int fd);

#endif