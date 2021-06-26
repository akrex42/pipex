#include "../includes/pipex.h"

char	*ft_strappend(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
	{
		i++;
	}
	str = (char *)malloc(i + 2);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	char	*buf;

	buf = (char *)malloc(2);
	*line = malloc(1);
	if ((*line == NULL) || !buf)
		return (-1);
	*line[0] = '\0';
	while ((read(fd, buf, 1)) > 0)
	{
		buf[1] = '\0';
		if (buf[0] == '\n')
			break ;
		*line = ft_strappend(*line, buf[0]);
	}
	free(buf);
	return (0);
}
