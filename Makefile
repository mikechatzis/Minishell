# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/18 18:00:18 by mchatzip          #+#    #+#              #
#    Updated: 2021/11/16 14:00:51 by mchatzip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = minishell

LIBFT_PATH = libft/

LIBFT_LIB  = libft.a

SRCS_FILES = minishell.c commands.c
				
SRCS_OBJS  = ${SRCS_FILES:.c=.o}

CC         = gcc

CFLAGS     = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS    = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

all:				${NAME}

${NAME}:    ${SRCS_OBJS} pmake
			${CC} ${CFLAGS} -o ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS} -L/usr/local/lib -I/usr/local/include -lreadline

pmake:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean  
			${RM} ${SRCS_OBJS}

fclean: 	clean
			${RM} ${NAME}

re:         fclean all

.PHONY:     all clean fclean re