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

void	execute_processes(t_all *all)
{
	int		j;
	char	*paths;
	int		exit_status;

	j = 0;
	paths = NULL;
	if (all->flag_path)
		execve(all->cmd[0], all->cmd, all->env);
	else
	{
		while (all->path[j] != NULL)
		{
			execute_processes_2(all, paths, j);
			j++;
		}
	}
	exit_status = errno;
	print_enoent(exit_status, all);
	exit (errno);
}

void	children_processes(t_all *all, t_list *lst, int i)
{
	if (i == 0)
		file_1_handling(all, i);
	else if (i == all->commands_amount - 1)
		file_2_handling(all, i);
	else
	{
		dup2(all->pipe_fd[i - 1][0], STDIN_FILENO);
		dup2(all->pipe_fd[i][1], STDOUT_FILENO);
	}
	close_pipes(all);
	create_cmd(all, lst);
	find_path(all);
	execute_processes(all);
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
			children_processes(all, lst, i);
		i++;
		lst = lst->next;
	}
}
