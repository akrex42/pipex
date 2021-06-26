#include "../includes/pipex.h"

void	create_here_doc(t_all *all)
{
	all->fd_in = open(all->argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (all->fd_in == -1)
	{
		perror(all->argv[2]);
		exit(1);
	}
	while (1)
	{
		ft_putchar_fd('>', 1);
		get_next_line(1, &all->line);
		if (ft_strlen(all->argv[2]) != ft_strlen(all->line))
		{
			ft_putstr_fd(all->line, all->fd_in);
			ft_putchar_fd('\n', all->fd_in);
		}
		else
		{
			if (!ft_strncmp(all->argv[2], all->line, ft_strlen(all->line)))
				break ;
			else
			{
				ft_putstr_fd(all->line, all->fd_in);
				ft_putchar_fd('\n', all->fd_in);
			}
		}
	}
	close(all->fd_in);
	all->fd_in = open(all->argv[2], O_RDONLY, 0777);
	unlink(all->argv[2]);
	dup2(all->fd_in, 0);
	close(all->fd_in);
}

void	find_path(t_all *all)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*value;

	tmp = NULL;
	tmp1 = NULL;
	j = 0;
	while (all->env[j] != NULL)
	{
//		tmp1 = all->env[j];
		value = ft_substr(all->env[j], 0, ft_strlen(all->env[j])
				- ft_strlen(ft_strchr(all->env[j], '=')));
		tmp = value;
		if (ft_strncmp("PATH", value, 5) == 0)
		{
			all->path = ft_split(all->env[j], ':');
			free(tmp);
//			free(tmp1);
			break ;
		}
		free(tmp);
//		free(tmp1);
		j++;
	}
}

void	print_error(char *arg)
{
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
}
