#include "../includes/pipex.h"

void	free_func(t_all *all, t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = NULL;
	while (i < all->commands_amount_pipes)
	{
		free(all->pipe_fd[i]);
		i++;
	}
	free(all->pipe_fd);
	free(all->pid);
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

int	init_list(int i, char **argv, t_list **lst)
{
	t_list	**head;

	head = lst;
	*lst = ft_lstnew(argv[i]);
	i++;
	while (argv[i + 1] != NULL)
	{
		ft_lstadd_back(lst, ft_lstnew(argv[i]));
		i++;
	}
	lst = head;
	return (i);
}

t_list	*init_commands_amount(t_all *all, char **argv, t_list *lst)
{
	int	i;

	i = 0;
	all->flag = 0;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])))
	{
		all->flag = 1;
		i = 3;
	}
	else
	{
		i = 2;
	}
	i = init_list(i, argv, &lst);
	if (all->flag)
	{
		all->commands_amount = i - 3;
		all->commands_amount_pipes = i - 4;
	}
	else
	{
		all->commands_amount = i - 2;
		all->commands_amount_pipes = i - 3;
	}
	return (lst);
}

void	init_struct(t_all *all, int argc, char **argv, char **env)
{
	int	i;

	i = 0;
	all->pid = malloc(all->commands_amount * sizeof(pid_t));
	all->line = NULL;
	all->env = env;
	all->argv = argv;
	all->argc = argc;
	all->path = NULL;
	all->cmd = NULL;
	all->flag_path = 0;
	all->errnum = 0;
	all->pipe_fd = (int **)malloc(all->commands_amount_pipes * sizeof(int *));
	while (i < all->commands_amount_pipes)
	{
		all->pipe_fd[i] = (int *)malloc(2 * sizeof(int));
		i++;
	}
}

void	execute_processes_2(t_all *all, char *paths, int j)
{
	char	*tmp;
	char	*tmp1;

	tmp = NULL;
	tmp1 = NULL;
	tmp = all->path[j];
	paths = ft_strjoin(all->path[j], all->cmd[0]);
	tmp1 = paths;
	free(tmp);
	if (access(paths, X_OK) == 0)
		execve(paths, all->cmd, all->env);
	free(tmp1);
}
