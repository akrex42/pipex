#include "../includes/pipex.h"

int main(int argc, char *argv[], char **envp)
{
	int		fd_in;
	int		fd_out;
	int		i;
	pid_t	*pid;
	char	**path;
	int		commands_amount;
	int		commands_amount_pipes;
	char	*line = NULL;

	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		i = 3;
	}
	else
	{
		i = 2;
	}
	t_list *lst = ft_lstnew(argv[i]);
	t_list *head = lst;
	i++;
	while (argv[i + 1] != NULL)
	{
		ft_lstadd_back(&lst, ft_lstnew(argv[i]));
		i++;
	}
	lst = head;
	if (!ft_strncmp(argv[1], "here_doc", 9))
	{
		commands_amount = i - 3;
		commands_amount_pipes = i - 4;
	}
	else
	{
		commands_amount = i - 2;
		commands_amount_pipes = i - 3;
	}
	pid = malloc(commands_amount * sizeof(pid_t)); // free
//	printf("%d", commands_amount);
//	t_list *elem = lst; // to print a list
//	while (elem)
//	{
//		printf("%s\n", elem->content);
//		elem = elem->next;
//	}
	int		pipe_fd[commands_amount_pipes][2]; // malloc
	i = 0;
	while (i < commands_amount_pipes)
	{
		if (pipe(pipe_fd[i]) == -1)
		{
			write(2, "my_bash: ", 9);
			perror(NULL);
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < commands_amount && lst)
	{
		pid[i] = fork();
		if (pid[i] == -1)
		{
			write(2, "my_bash: ", 9);
			perror(NULL);
			return (1);
		}
		else if (pid[i] == 0) // children
		{
			if (i == 0)
			{
				if (!ft_strncmp(argv[1], "here_doc", 9))
				{
					fd_in = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0777);
					if (fd_in == -1)
					{
						write(2, "my_bash: ", 9);
						perror(argv[2]);
						exit(1);
					}
					while (1)
					{
						ft_putchar_fd('>', 1);
						get_next_line(1, &line);
						if (!ft_strncmp(argv[2], line, ft_strlen(line)))
						{
							break ;
						}
						ft_putstr_fd(line, fd_in);
						ft_putchar_fd('\n', fd_in);
					}
					close(fd_in);
					fd_in = open(argv[2], O_RDONLY, 0777);
					unlink(argv[2]);
					dup2(fd_in, 0);
					close(fd_in);
				}
				else
				{
					fd_in = open(argv[1], O_RDONLY);
					if (fd_in == -1)
					{
						write(2, "my_bash: ", 9);
						perror(argv[1]);
						exit(1);
					}
					dup2(fd_in, 0);
					close(fd_in);
				}
				dup2(pipe_fd[i][1], 1);
			}
			else if (i == commands_amount - 1)
			{
				dup2(pipe_fd[i - 1][0], 0);
				if (!ft_strncmp(argv[1], "here_doc", 9))
				{
					fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
					if (fd_out == -1)
					{
						write(2, "my_bash: ", 9);
						perror(argv[argc - 1]);
						exit(1);
					}
					dup2(fd_out, 1);
					close(fd_out);
				}
				else
				{
					fd_out = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
					if (fd_out == -1)
					{
						write(2, "my_bash: ", 9);
						perror(argv[argc - 1]);
						exit(1);
					}
					dup2(fd_out, 1);
					close(fd_out);
				}
			}
			else
			{
				dup2(pipe_fd[i - 1][0], 0);
				dup2(pipe_fd[i][1], 1);
			}
			int j = 0;
			while (j < commands_amount_pipes)
			{
				close(pipe_fd[j - 1][0]);
				close(pipe_fd[j][1]);
				j++;
			}
			char **cmd = ft_split(lst->content, ' ');
			cmd[0] = ft_strjoin("/", cmd[0]);
			j = 0;
			while (envp[i] != NULL)
			{
				if (ft_strncmp("PATH", ft_substr(envp[j], 0, ft_strlen(envp[j]) - ft_strlen(ft_strchr(envp[j], '='))), 5) == 0)
				{
					path = ft_split(envp[j], ':');
					break ;
				}
				j++;
			}
			j = 0;
			while (path[j] != NULL)
			{
				if (access(ft_strjoin(path[j], cmd[0]), F_OK) == 0) // may be X_OK
				{
					execve(ft_strjoin(path[j], cmd[0]), cmd, envp);
				}
				j++;
			}
			exit (errno);
		}
		i++;
		lst = lst->next;
	}
	int j = 0;
	while (j < commands_amount_pipes)
	{
		close(pipe_fd[j - 1][0]);
		close(pipe_fd[j][1]);
		j++;
	}
	i = 0;
	int exec_ret;
	while (i < commands_amount)
	{
		waitpid(pid[i], &exec_ret, 0);
		exec_ret = WEXITSTATUS(exec_ret);
		if (exec_ret != 0)
		{
			if (exec_ret == 2)
			{
				write(2, "my_bash: ", 9);
				ft_putstr_fd(argv[argc - i], 2);
				ft_putstr_fd("command not found", 2);
				ft_putchar_fd('\n', 2);
			}
			else if (exec_ret != 1)
			{
				write(2, "my_bash: ", 9);
				ft_putstr_fd(strerror(exec_ret), 2);
				ft_putchar_fd('\n', 2);
			}
		}
		i++;
	}
	free (pid);
	return (0);
}
