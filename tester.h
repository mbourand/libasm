#ifndef TESTER_H
# define TESTER_H

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>

size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
ssize_t			ft_read(int fd, void *buf, size_t count);
ssize_t			ft_write(int fd, const void *buf, size_t count);
char			*ft_strdup(const char *s);

#endif
