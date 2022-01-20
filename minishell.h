/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:15:48 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/20 16:06:44 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <signal.h>
# include <stdbool.h>
# include "libft/libft.h"

char	**g_env;

typedef struct s_nums
{
	int		hlogc;
	int		hfd;
	int		envi;
	int		print;
	bool	sig;
}	t_nums;

void	execls(char *b);
void	execpwd(void);
void	dhandler(int signum);
void	execcd(char *b);
void	loghistory(char *b, t_nums *nums);
void	execprog(char *b);
void	exec(char *b);
void	ukncommand(char *b);
int		sighandler(void);
void	exececho(char *b);
int		countchar(char *s, char c);
int		prints(char *s, t_nums *n);
int		echoerrcheck(char *b);
void	execexport(char *b);
void	execunset(char *b);
char	*parseenv(char **ENV, char *name);
char	*printvar(char *s);
int		namecmp(char *s, char *b);
int		namecmpu(char *s, char *b);
int		namecmpx(char **s, char *b);
void	execenv(char *b);
char	*saveenv(void);
void	restoreenv(char *s);
void	free3(void *s, void *sp, void *sav);
void	setenviron(void);
char	**processinput(char	*b);
char	*handlespace(char *b);
char	*handlesquotes(char *b);
char	*handledquotes(char *b);
char	*singledollar(char *b);
char	*handlepiddis(char *b);
int		isnumeric(char *b);
char	*handleschars(char	*b);
void	execseq(char *b, char **rpaths, char **argvs, char *fpath);
char	*emptyname(char *s);
char	*zeroorhash(char *s);
char	*allelse(char *b, char *s, char *name);
int		squoteerr(int i, char *b);
int		dquoteerr(int i, char *b);
void	execinenv(int i, char *s, char *sub, char **sp);
void	printenv(void);

#endif