#include "../includes/pipex.h"

void	print_enoent(int exit_status, t_all *all)
{
	if (exit_status == ENOENT)
	{
		print_error(&(all->cmd[0][1]));
		ft_putendl_fd("command not found", 2);
	}
	else if (exit_status == EACCES)
		perror(all->cmd[0]);
}

int	internal_cycle(t_all *all)
{
	get_next_line(STDOUT_FILENO, &all->line);
	if (ft_strlen(all->argv[2]) != ft_strlen(all->line))
	{
		ft_putstr_fd(all->line, all->fd_in);
		ft_putchar_fd('\n', all->fd_in);
	}
	else
	{
		if (!ft_strncmp(all->argv[2], all->line, ft_strlen(all->line)))
			return (1);
		else
		{
			ft_putstr_fd(all->line, all->fd_in);
			ft_putchar_fd('\n', all->fd_in);
		}
	}
	return (0);
}

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
		if (internal_cycle(all))
			break ;
	}
	close(all->fd_in);
	all->fd_in = open(all->argv[2], O_RDONLY, 0777);
	unlink(all->argv[2]);
	dup2(all->fd_in, STDIN_FILENO);
	close(all->fd_in);
}

void	find_path(t_all *all)
{
	int		j;
	char	*tmp;
	char	*value;

	tmp = NULL;
	j = 0;
	while (all->env[j] != NULL)
	{
		value = ft_substr(all->env[j], 0, ft_strlen(all->env[j])
				- ft_strlen(ft_strchr(all->env[j], '=')));
		tmp = value;
		if (ft_strncmp("PATH", value, 5) == 0)
		{
			all->path = ft_split(all->env[j], ':');
			free(tmp);
			break ;
		}
		free(tmp);
		j++;
	}
}

void	print_error(char *arg)
{
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
}
