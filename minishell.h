/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:15:48 by mchatzip          #+#    #+#             */
/*   Updated: 2021/12/01 18:23:19 by mchatzip         ###   ########.fr       */
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
# include "libft/libft.h"

char	*g_path;
char	**ENV;

typedef struct s_nums
{
	int	hlogc;
	int	hfd;
	int	envi;
}	t_nums;

void	execls(char *b);
void	execpwd(void);
void	execcd(char *b);
void	loghistory(char *b, t_nums *nums);
void	execprog(char *b);
void	exec(char *b);
void	ukncommand(char *b);
void	bslashhandler(void);
void	exececho(char *b);
int		countchar(char *s, char c);
int		prints (char *s);
char	*prints2(char *s);
int		echoerrcheck(char *b);
void	execexport(char *b);
char	*parseenv(char **ENV, char *name);
int		printvar(char *s);
int		namecmp(char *s, char *b);

#endif