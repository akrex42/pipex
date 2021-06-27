#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# include "../libft/libft.h"

typedef struct s_all
{
	pid_t	*pid;
	int		fd_in;
	int		fd_out;
	char	**path;
	int		flag;
	int		flag_path;
	int		errnum;
	int		commands_amount;
	int		commands_amount_pipes;
	char	*line;
	char	**env;
	char	**argv;
	int		argc;
	int		**pipe_fd;
	char	**cmd;
}				t_all;

int				get_next_line(int fd, char **line);
void			create_redir(t_all *all);
void			create_double_redir(t_all *all);
void			create_fd_in(t_all *all);
void			create_here_doc(t_all *all);
void			wait_for_commands(t_all *all, int n);
void			create_cmd(t_all *all, t_list *lst);
void			execute_processes(t_all *all);
void			children_processes(t_all *all, t_list *lst, int i);
void			create_processes(t_all *all, t_list *lst);
void			find_path(t_all *all);
void			file_2_handling(t_all *all, int i);
void			file_1_handling(t_all *all, int i);
int				init_list(int i, char **argv, t_list **lst);
t_list			*init_commands_amount(t_all *all, char **argv, t_list *lst);
void			init_struct(t_all *all, int argc, char **argv, char **env);
void			close_pipes(t_all *all);
void			create_pipes(t_all *all);
void			free_func(t_all *all, t_list *lst);
void			print_error(char *arg);
int				internal_cycle(t_all *all);
void			print_enoent(int exit_status, t_all *all);

#endif
