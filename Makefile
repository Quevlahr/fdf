# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/15 21:18:09 by quroulon          #+#    #+#              #
#    Updated: 2016/03/15 21:18:16 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra

SRC 		= 	main.c utilities.c read.c menu.c trace1.c mlx_funct.c verif.c \
				trace2.c

LIB			=	-Llibft -lft -Lminilibx_macos -lmlx -framework OpenGL \
				-framework AppKit

OBJ			=	$(SRC:.c=.o)
OBJ2		=	$(wildcard *.gch)

HEADER 		=	libft/libft.h


all: $(NAME)

.SILENT : $(NAME)
$(NAME): $(OBJ)
	@make -sC libft/
	@make -sC minilibx_macos/
	@$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "COMPILATION DONE"

.SILENT : clean
clean:
	@make clean -sC libft/
	@make clean -sC minilibx_macos/
	@rm -f $(OBJ) $(OBJ2)
	@echo "CLEAN DONE"

.SILENT : fclean
fclean: clean
	@make fclean -sC libft/
	@rm -f $(NAME)
	@echo "FCLEAN DONE"

re: fclean all
