/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:19:39 by mchatzip          #+#    #+#             */
/*   Updated: 2022/01/24 18:17:44 by mchatzip         ###   ########.fr       */
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
	dprintf(fd, "%s", buff);
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
		dprintf(fd, "%c", *buff);
		if (*buff)
			buff++;
	}
	buff -= i;
	free(buff);
	return (b);
}

static char	*handlespacexp(char *b, int fd)
{
	dprintf(fd, " ");
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
	if (*b != ' ' && *b != '$' && *b != '\'' && *b != '"')
	{
		if ((dprintf(fd, "%c", *b)) == -1)
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

	fd = open("exporttmpfile", O_CREAT | O_TRUNC | O_RDWR, 0755);
	i = 0;
	ret = malloc(1000);
	while (*b)
		b = handlescharsxp(b, fd);
	lseek(fd, 0, SEEK_SET);
	while ((read(fd, &c, 1)))
		ret[i++] = c;
	ret[i] = 0;
	close(fd);
	return (ret);
}
