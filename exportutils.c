/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/31 13:30:28 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handlesquotesxp(char *b, int fd)
{
	char	*buff;
	int		i;

	b++;
	i = 0;
	while (b[i] && b[i] != '\'')
		i++;
	buff = ft_substr(b, 0, i);
	write(fd, buff, ft_strlen(buff));
	b += ft_strlen(buff) + 1;
	free(buff);
	return (b);
}

static char	*handledquotesxp(char *b, int fd)
{
	char	*buff;
	int		i;

	b++;
	i = 0;
	while (b[i] && b[i] != '"')
		i++;
	buff = ft_substr(b, 0, i);
	b += ft_strlen(buff) + 1;
	i = ft_strlen(buff);
	while (*buff)
	{
		if (*buff == '$')
			buff = printvarxp(buff, fd);
		if (*buff)
		{
			write(fd, &*buff, 1);
			buff++;
		}
	}
	buff -= i;
	free(buff);
	return (b);
}

static char	*handlespacexp(char *b, int fd)
{
	write(fd, " ", 1);
	while (*b == ' ')
		b++;
	return (b);
}

static char	*handlescharsxp(char *b, int fd)
{
	if (*b == ' ')
		b = handlespacexp(b, fd);
	if (*b == '\'')
		b = handlesquotesxp(b, fd);
	if (*b == '"')
		b = handledquotesxp(b, fd);
	if (*b == '$')
		b = printvarxp(b, fd);
	if (*b && *b != ' ' && *b != '$' && *b != '\'' && *b != '"')
	{
		if ((write(fd, &*b, 1)) == -1)
			perror("");
		b++;
	}
	return (b);
}

char	*exportout(char *b)
{
	int		fd;
	int		i;
	char	c;
	char	*ret;

	ret = malloc(1000);
	fd = open("/Users/mchatzip/goinfre/Minishell/exporttmpfile",
			O_CREAT | O_TRUNC | O_RDWR, 0755);
	if (fd == -1)
		perror("open: ");
	if (fd == -1)
		return (ret);
	i = 0;
	if (echoerrcheck(b))
		return ("");
	while (*b == ' ')
		b++;
	while (*b)
		b = handlescharsxp(b, fd);
	lseek(fd, 0, SEEK_SET);
	while ((read(fd, &c, 1)))
		ret[i++] = c;
	ret[i] = 0;
	close(fd);
	return (ret);
}
