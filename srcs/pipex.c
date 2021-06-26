#include "../includes/pipex.h"

int	main(int argc, char *argv[], char **env)
{
	t_all	all;
	t_list	*lst;

	lst = NULL;
	lst = init_commands_amount(&all, argv, lst);
	init_struct(&all, argc, argv, env);
	create_pipes(&all);
	create_processes(&all, lst);
	close_pipes(&all);
	wait_for_commands(&all, all.commands_amount);
	free_func(&all, lst); // free lst
//	sleep (100);
	return (0);
}
