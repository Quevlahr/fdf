# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/19 16:00:15 by quroulon          #+#    #+#              #
#    Updated: 2016/03/10 11:16:11 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	fdf.c creation.c utilities.c trace.c menu.c

LIB			=	-Llibft -lft -Lminilibx_macos -lmlx -framework OpenGL \
				-framework AppKit

OBJ			=	$(SRC:.c=.o)

HEADER 		=	libft/includes/libft.h


all: $(NAME)

.SILENT : $(NAME)
$(NAME):
	# cd libft/ && $(MAKE) re
	# cd minilibx_macos/ && $(MAKE) re
	$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

.SILENT : clean
clean:
	# cd libft/ && $(MAKE) clean
	# cd minilibx_macos/ && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gch

.SILENT : fclean
fclean: clean
	# cd libft/ && $(MAKE) fclean
	# cd minilibx_macos/ && $(MAKE) clean
	rm -f $(NAME)

re: fclean all

