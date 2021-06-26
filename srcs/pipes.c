#include "../includes/pipex.h"

void	close_pipes(t_all *all)
{
	int	j;
	int	i;

	j = 1;
	i = 0;
	while (j - 1 < all->commands_amount_pipes && i < all->commands_amount_pipes)
	{
		close(all->pipe_fd[j - 1][0]);
		close(all->pipe_fd[i][1]);
		j++;
		i++;
	}
}

void	create_pipes(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->commands_amount_pipes)
	{
		if (pipe(all->pipe_fd[i]) == -1)
		{
			perror(NULL);
			exit(1);
		}
		i++;
	}
}
