#include "../includes/pipex.h"

int main(int argc, char *argv[])
{
	int		fd_in;
	int		fd_out;
	int		pipe_fd[2];
	pid_t	pid_1;
	pid_t	pid_2;

	if (argc != 5)
	{
		return (1);
	}
	if (pipe(pipe_fd) == -1)
	{
		write(2, "my_bash: ", 9);
		perror(NULL);
		return (1);
	}
	pid_1 = fork();
	if (pid_1 == -1)
	{
		write(2, "my_bash: ", 9);
		perror(NULL);
		return (1);
	}
	if (pid_1 == 0) // child 1
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		close(pipe_fd[1]);
		fd_in = open(argv[1], O_RDONLY);
		if (fd_in == -1)
		{
			write(2, "my_bash: ", 9);
			perror(argv[1]);
			exit(1);
		}
		dup2(fd_in, 0);
		close(fd_in);
		char **cmd1 = ft_split(argv[2], ' ');
		execvp(cmd1[0], cmd1);
		exit (errno);
	}
	pid_2 = fork();
	if (pid_2 == -1)
	{
		write(2, "my_bash: ", 9);
		perror(NULL);
		return (1);
	}
	if (pid_2 == 0) // child 2
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], 0);
		close(pipe_fd[0]);
		fd_out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if (fd_out == -1)
		{
			write(2, "my_bash: ", 9);
			perror(argv[4]);
			exit(1);
		}
		dup2(fd_out, 1);
		close(fd_out);
		char **cmd2 = ft_split(argv[3], ' ');
		execvp(cmd2[0], cmd2);
		exit (errno);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}
