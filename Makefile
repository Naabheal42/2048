# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gallard <gallard@student.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/28 14:41:43 by gallard           #+#    #+#              #
#    Updated: 2015/03/01 18:03:48 by gallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

DFLAGS		=	-Wextra -Wall -g 
RFLAGS		=	-Wextra -Wall -Werror -O2
CFLAGS		=	$(RFLAGS)

SRCS		=						\
				demika2.c			\
				init_env.c			\
				add_num.c			\
				dmk_disp.c			\
				dmk_loop.c			\
				dmk_color.c			\
				grid_up.c			\
				grid_down.c			\
				grid_right.c		\
				grid_left.c			\
				grid_hasdouble.c	\
				ft_putchar.c		\
				ft_putnbr.c			\
				ft_strcpy.c			\

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	-I.

LIBS		=	-lncurses

TARGET		=	game_2048

.PHONY:		all clean fclean re

all:		$(TARGET)

$(TARGET):	$(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LIBS)

.c.o:
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			@echo "Cleaning up the mess..."
			$(RM) $(OBJS)

fclean:
			$(RM) $(OBJS)
			$(RM) $(TARGET)

re:			fclean all

#eof
