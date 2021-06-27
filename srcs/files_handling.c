#include "../includes/pipex.h"

void	create_redir(t_all *all)
{
	all->fd_out = open(all->argv[all->argc - 1], O_WRONLY | O_TRUNC
			| O_CREAT, 0777);
	if (all->fd_out == -1)
	{
		perror(all->argv[all->argc - 1]);
		exit(1);
	}
	dup2(all->fd_out, STDOUT_FILENO);
	close(all->fd_out);
}

void	create_double_redir(t_all *all)
{
	all->fd_out = open(all->argv[all->argc - 1], O_WRONLY | O_CREAT
			| O_APPEND, 0777);
	if (all->fd_out == -1)
	{
		perror(all->argv[all->argc - 1]);
		exit(1);
	}
	dup2(all->fd_out, STDOUT_FILENO);
	close(all->fd_out);
}

void	create_fd_in(t_all *all)
{
	all->fd_in = open(all->argv[1], O_RDONLY);
	if (all->fd_in == -1)
	{
		perror(all->argv[1]);
		exit(1);
	}
	dup2(all->fd_in, STDIN_FILENO);
	close(all->fd_in);
}

void	file_2_handling(t_all *all, int i)
{
	dup2(all->pipe_fd[i - 1][0], STDIN_FILENO);
	if (all->flag)
		create_double_redir(all);
	else
		create_redir(all);
}

void	file_1_handling(t_all *all, int i)
{
	if (all->flag)
		create_here_doc(all);
	else
		create_fd_in(all);
	dup2(all->pipe_fd[i][1], STDOUT_FILENO);
}
