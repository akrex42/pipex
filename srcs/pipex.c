#include "../includes/pipex.h"

int	main(int argc, char *argv[], char **env)
{
	t_all	all;
	t_list	*lst;

	lst = NULL;
	if ((argc < 5) || (!ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1]))
			&& argc < 6 ))
	{
		ft_putendl_fd("No args", STDERR_FILENO);
		exit(1);
	}
	lst = init_commands_amount(&all, argv, lst);
	init_struct(&all, argc, argv, env);
	create_pipes(&all);
	create_processes(&all, lst);
	close_pipes(&all);
	wait_for_commands(&all, all.commands_amount);
	free_func(&all, lst);
	return (0);
}
