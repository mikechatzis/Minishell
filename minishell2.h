/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:08:45 by bkeskint          #+#    #+#             */
/*   Updated: 2022/03/11 13:45:16 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL2_H
# define MINISHELL2_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <limits.h>

/*
keep_stdout;	is neccessary to dup()
			when there is output redirection without fork()
n_pipe;			number of subs for "|" "pipes"
*fd_pipe;		file descriptor for pipes
fd_io[2];		file decriptor for Standard I/O
i_file;			>=1 if string array contains "<", otherwise =0
i2_file;		>=1 if string array contains "<<", otherwise =0
o_file;			>=1 string array contains ">", otherwise =0
o2_file;		>=1 if string array contains ">>", otherwise =0
builtin_flag;	if =1 spawning a new process is skipped
flag_sq;		flag for single quotes when handling comments
flag_dq;		flag for double quotes when handling comments
*/

typedef struct s_parameters
{
	char	**env;
	int		exit;
	char	*line;
	pid_t	pid;
	int		keep_stdout;
	char	**command;
	char	**pipe_command;
	int		n_pipe;
	int		*fd_pipe;
	int		fork_flag;
	int		fd_io[2];
	char	*buf;
	int		i;
	int		q;
	int		qq;
	int		exit_status;
	int		input_flag;
	int		i_file;
	int		o_file;
	int		i2_file;
	int		o2_file;
	char	*path;
	int		builtin_flag;
	int		flag_sq;
	int		flag_dq;
}	t_parameters;

char			**arraydup(char **source);
int				arraylenght(char **source);
void			initialization(t_parameters *params);
void			initialization_pipe(t_parameters *params);
void			signals(void);
void			handler(int signum, siginfo_t *info, void *unused);
char			**arguments(char const *s, char c);
void			perror(const char *s);
void			end(const char *s);
void			dup_failed(t_parameters *params);
void			fork_failed(t_parameters *d);
void			chdir_failed(const char *s);
void			execve_failed(const char *s);
void			pipe_failed(t_parameters *params);
void			open_failed(t_parameters *params);
void			write_failed(t_parameters *params, char *line);
void			ft_exit(char **args);
void			clean_exit(char **args);
int				ifspace(char *line);
void			route(t_parameters *params);
void			drive(t_parameters *params);
size_t			arguments_counter(char const *s, char c);
void			next_argument(char **string, size_t *len, char c);
void			quot_handle_2(char **string, size_t *i, size_t *len);
void			quot_handle(const char *s, size_t *i);
void			pipe_handler(t_parameters *params, int i, int j);
int				fork_handler(t_parameters *params, int *i, int *j);
void			env_handler(t_parameters *params, char **command);
char			*check(t_parameters *params, char *s);
char			*newstring(size_t	size);
char			*addchar(char *str, char c);
int				freesplit(char **split);
void			q_handler(t_parameters *params, char *s);
void			qq_handler(t_parameters *params, char *s);
char			*parse_v(t_parameters *params, char *s);
void			jumper_v(t_parameters *params, char *s);
int				arrlen(char **src);
char			**arrdup(char **src);
char			**strarrayadd(char **arr, char *str);
char			*qtoback(char **s);
char			*qqpasteback(char	**buf);
int				single_par(t_parameters *params, char *s);
int				isspace(int ch);
char			*envget(t_parameters *params, char *str);
int				is_var(t_parameters *params, char *s);
char			*double_quot(t_parameters *params, char *s);
char			*trimmer(char *s);
int				pass_executable(char **args);
int				check_command(char	*command, char *next_command);
void			builtins_jumper(t_parameters *params, char **args);
void			do_echo(t_parameters *params, char **args);
int				n_checker(char *s);
void			ft_put(t_parameters *params, char **args, int i);
void			do_pwd(t_parameters *params, char **args);
void			do_cd(t_parameters *params, char **args);
void			do_export(t_parameters *params, char **args);
void			exportarg(t_parameters *params, char **args);
char			*cut_double_quots(char *s);
char			*cut_single_quot(char *s);
int				do_search(t_parameters *params, char **args, int j);
void			replace_string(char **array, int i, char *s);
int				sort_print(t_parameters *params);
int				check_digit(char *s);
void			do_exit(char **args);
void			do_env(t_parameters *params, char **args);
void			delete_last(char **args);
int				unset_helper1(t_parameters *params, char **args);
void			i_handler(t_parameters *params, char **args);
void			o_handler(t_parameters *params, char **args);
char			**unset_helper2(char **array, int i);
int				move_back(char **args, int position);
int				handle_i(t_parameters *params, char **args, int *i);
int				handle_i_join(t_parameters *params, char **args, int *i);
int				handle_i2(t_parameters *params, char **args, int *i);
int				handle_i2_join(t_parameters *params, char **args, int *i);
void			access_i_file(t_parameters *params, char **args);
void			writer_handle(char	*eof, t_parameters *params);
int				gnl(int fd, char **line);
int				handle_o(t_parameters *params, char **args, int *i);
int				handle_o_join(t_parameters *params, char **args, int *i);
int				handle_o2(t_parameters *params, char **args, int *i);
int				handle_o2_join(t_parameters *params, char **args, int *i);
void			command_redirection(t_parameters *params);
void			execute_handler(t_parameters *params, int i);
int				check_builtin(char *command);
int				is_null(t_parameters *params, char *command);
void			path_checker(t_parameters *params, char *command);
void			do_comments(t_parameters *params);
void			second_main(char const *s);

#endif