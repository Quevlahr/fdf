# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/19 16:00:15 by quroulon          #+#    #+#              #
#    Updated: 2016/02/19 16:00:32 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	a.out

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g

SRC 		= 	fdf.c

LIB			=	libft/libft.a -lmlx -framework OpenGL -framework AppKit

OBJ			=	$(SRC:.c=.o)

HEADER 		=	libft/includes/libft.h


all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	# cd libft/ && $(MAKE) re
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	# cd libft/ && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gch

.SILENT : fclean
fclean: clean
	# cd libft/ && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

