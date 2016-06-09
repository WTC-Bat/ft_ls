/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 15:04:06 by mlamarre          #+#    #+#             */
/*   Updated: 2016/06/07 16:26:01 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*read_line(const int fd, int *status, int *exlen)
{
	void	*b;
	char	*s;

	b = (char *)malloc(sizeof(char));
	s = ft_strnew(0);
	*exlen = 0;
	while (*(char *)b != '\n')
	{
		b = (char *)malloc(sizeof(char));
		*exlen += read(fd, b, 1);
		if (*(char *)b != '\n')
			ft_strcat(s, b);
		if (*(char *)b == '\0')
		{
			*status = 0;
			return (NULL);
		}
		//free(b);
	}
	return (s);
}

int			get_next_line(const int fd, char **line)
{
	char		*ln;
	int			status;
	static int	exlen;

	ln = "";
	status = 1;
	if (fd < 0)
		return (-1);
	if (ln != NULL)
		ln = ft_strnew(BUFF_SIZE + exlen);
	ln = read_line(fd, &status, &exlen);
	*line = ln;
	free(ln);
	return (status);
}
