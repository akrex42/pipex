#include "../includes/pipex.h"

void	wait_for_commands(t_all *all, int n)
{
	int	exec_ret;
	int	i;

	i = 0;
	while (i < n)
	{
		waitpid(all->pid[i], &exec_ret, 0);
		exec_ret = WEXITSTATUS(exec_ret);
		if (exec_ret == 2)
		{
			if (all->flag && !all->flag_exit) // AAAAAAAAA
			{
				print_error(all->argv[i + 3]);
				ft_putendl_fd("command not found", 2);
			}
			else if (!all->flag_exit)
			{
				print_error(all->argv[i + 2]);
				ft_putendl_fd("command not found", 2);
			}
		}
		i++;
	}
}

void	create_cmd(t_all *all, t_list *lst)
{
	char	*tmp;

	tmp = NULL;
	all->cmd = ft_split(lst->content, ' ');
	if (ft_strchr(all->cmd[0], '/') == NULL)
	{
		tmp = all->cmd[0];
		all->cmd[0] = ft_strjoin("/", all->cmd[0]);
		free(tmp);
	}
	else
		all->flag_path = 1;
}

int	execute_processes(t_all *all)
{
	int		j;
	char	*paths;
	char 	*tmp;
	char 	*tmp1;

	j = 0;
	tmp = NULL;
	tmp1 = NULL;
	if (all->flag_path)
		execve(all->cmd[0], all->cmd, all->env);
	else
	{
		while (all->path[j] != NULL)
		{
			tmp = all->path[j];
			paths = ft_strjoin(all->path[j], all->cmd[0]);
			tmp1 = paths;
			free(tmp);
			if (access(paths, X_OK) == 0)
			{
//				free(tmp1);
				all->flag_exit = 1;
				execve(paths, all->cmd, all->env);
			}
			free(tmp1);
			j++;
		}
	}
	return (errno);
}

int	children_processes(t_all *all, t_list *lst, int i)
{
	if (i == 0)
		file_1_handling(all, i);
	else if (i == all->commands_amount - 1)
		file_2_handling(all, i);
	else
	{
		dup2(all->pipe_fd[i - 1][0], 0);
		dup2(all->pipe_fd[i][1], 1);
	}
	close_pipes(all);
	create_cmd(all, lst);
	find_path(all);
	errno = execute_processes(all);
	exit (errno);
}

void	create_processes(t_all *all, t_list *lst)
{
	int	i;

	i = 0;
	while (i < all->commands_amount && lst)
	{
		all->pid[i] = fork();
		if (all->pid[i] == -1)
		{
			wait_for_commands(all, i);
			perror(NULL);
			exit(1);
		}
		else if (all->pid[i] == 0)
		{
//			ft_putnbr_fd(errno, 2);
			errno = children_processes(all, lst, i);
			if (all->flag && errno)
				print_error(all->argv[i + 3]);
			else if (errno)
				print_error(all->argv[i + 2]);
			ft_putstr_fd(strerror(errno), 2);
			exit(1);
		}
		i++;
		lst = lst->next;
	}
}
