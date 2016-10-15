/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   demika2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gallard <gallard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:02:51 by gallard           #+#    #+#             */
/*   Updated: 2015/02/28 15:21:24 by gallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "demika2.h"

t_env	*g_env;

static void	sig_handler(int n)
{
	if (n == SIGWINCH)
	{
		endwin();
		initscr();
		refresh();
		clear();
		refresh();
		g_env->width = COLS - 1;
		g_env->height = LINES - 2;
		dmk_disp(g_env);
		refresh();
	}
	else
	{
		nocbreak();
		endwin();
	}
}

int			main(int ac, char *av[])
{
	t_env	env;

	(void)ac;
	(void)av;
	g_env = &env;
	srand(time(NULL));
	env.w = initscr();
	if (init_env(&env))
	{
		curs_set(0);
		cbreak();
		noecho();
		keypad(env.w, TRUE);
		signal(SIGQUIT, sig_handler);
		signal(SIGWINCH, sig_handler);
		loop(&env);
	}
	endwin();
	return (0);
}
