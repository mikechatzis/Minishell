# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 18:00:18 by mchatzip          #+#    #+#              #
#    Updated: 2022/02/07 13:09:52 by mchatzip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = minishell

LIBFT_PATH = libft/

LIBFT_LIB  = libft.a

SRCS_FILES = minishell.c commands.c commands2.c history.c utils.c utils2.c utils3.c utils4.c utils5.c echoutils.c \
			 utils6.c exportutils.c exportutils2.c exportutils3.c pipenredirutils.c utils7.c utils8.c pipeutils.c \
			 utils9.c utils10.c
				
SRCS_OBJS  = ${SRCS_FILES:.c=.o}

CC         = gcc

CFLAGS     = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS    = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

all:				${NAME}

${NAME}:    ${SRCS_OBJS} pmake
			${CC} ${CFLAGS} -g -o ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS} -L/usr/local/lib -I/usr/local/include -lreadline -L .brew/opt/readline/lib -I .brew/opt/readline/include

pmake:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean  
			${RM} ${SRCS_OBJS} history

fclean: 	clean
			${RM} ${NAME}

re:         fclean all

.PHONY:     all clean fclean re