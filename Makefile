# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: quroulon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/19 16:00:15 by quroulon          #+#    #+#              #
#    Updated: 2016/03/15 20:14:37 by quroulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	fdf

CC			= 	gcc
CFLAGS		= 	-Wall -Werror -Wextra -g

SRC 		= 	fdf.c creation.c utilities.c trace.c menu.c

LIB			=	-Llibft -lft -Lminilibx_macos -lmlx -framework OpenGL \
				-framework AppKit

OBJ			=	$(SRC:.c=.o)

HEADER 		=	libft/includes/libft.h


all: $(NAME)

.SILENT : $(NAME)
$(NAME):
#	@cd libft/ && $(MAKE) re
#	@cd minilibx_macos/ && $(MAKE) re
	@make -sC libft/
	@make -sC minilibx_macos/
	@$(CC) $(CFLAGS) -c $(HEADER) $(SRC)
	@$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo "COMPILATION DONE"

.SILENT : clean
clean:
	#@cd libft/ && $(MAKE) clean
	#@cd minilibx_macos/ && $(MAKE) clean
	@make clean -sC libft/
	@make clean -sC minilibx_macos/
	@rm -f $(OBJ)
	@rm -f *.gch
	@echo "CLEAN DONE"

.SILENT : fclean
fclean: clean
	#@cd libft/ && $(MAKE) fclean
	#@cd minilibx_macos/ && $(MAKE) clean
	@make fclean -sC libft/
	@rm -f $(NAME)
	@echo "FCLEAN DONE"

re: fclean all

