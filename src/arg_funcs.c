/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:02:29 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/09/02 10:54:13 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	lsargs_init(t_lsargs *lsargs)
{
	lsargs->show_all = 0;
	lsargs->long_form = 0;
	lsargs->recursive = 0;
	lsargs->reverse = 0;
	lsargs->order_time = 0;
	lsargs->path = NULL;
}

static void		lsargs_set(char c, t_lsargs *lsargs)
{
	if (c == 'a')
		lsargs->show_all = 1;
	else if (c == 'l')
		lsargs->long_form = 1;
	else if (c == 'r')
		lsargs->reverse = 1;
	else if (c == 't')
		lsargs->order_time = 1;
	else if (c == 'R')
		lsargs->recursive = 1;
	else if (c == 'Z')
		lsargs->all_members = 1;
}

/*
**	Could be improved. As is, will only recognize arg as a
**	path if it contains '/'
*/
int			arg_ispath(char *arg)
{
	if (ft_strchr(arg, '/') == NULL)
		return (0);
	return (1);
}

int			args_are_valid(char **argv)
{
	int		scnt;

	scnt = 1;
	while (argv[scnt] != '\0')
	{
		if ((arg_ispath(argv[scnt]) == 0) &&
			(ft_strchr(argv[scnt], '-') == NULL))
			return (0);
		scnt++;
	}
	return (1);
}

t_lsargs	analyze_args(char **argv)
{
	int			scnt;
	int			ccnt;
	t_lsargs	lsargs;

	scnt = 1;
	ccnt = 0;
	lsargs_init(&lsargs);
	lsargs.path = "./";
	if (args_are_valid(argv) == 0)
	{
		ft_putendl_fd("Error: Bad option format.", 2);
		exit(1);
	}
	while (argv[scnt] != NULL)
	{
		if (arg_ispath(argv[scnt]) == 1)
		{
			lsargs.path = argv[scnt];
			if (lsargs.path[ft_strlen(lsargs.path) - 1] != '/')
				lsargs.path = ft_appendc(lsargs.path, '/');
		}
		else
		{
			while (argv[scnt][ccnt] != '\0')
			{
				lsargs_set(argv[scnt][ccnt], &lsargs);
				ccnt++;
			}
		}
		ccnt = 0;
		scnt++;
	}
	return (lsargs);
}
