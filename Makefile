# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 09:28:50 by jponcele          #+#    #+#              #
#    Updated: 2015/01/05 09:28:54 by jponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

DIRSRC = ./srcs/
DIROBJ = ./.obj/

SRC = 	main.cpp\
		AModuleSimple.cpp\
		ModuleHostname.cpp\
		ModuleOSInfo.cpp\
		ModuleTime.cpp

OBJ = $(SRC:.cpp=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

HEADERS = ./headers/

CFLAGS = -Wall -Werror -Wextra -g
CC = g++

all: $(NAME)

$(NAME): $(DIROBJS)
	@printf 'Compiling %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(CC) $(CFLAGS) -o $@ $^ -lncurses

$(DIROBJ)%.o: $(DIRSRC)%.cpp
	@printf 'Compiling %s: [\033[32mDONE\033[0m]\n' '$^'
	@mkdir -p $(DIROBJ)
	@$(CC) $(CFLAGS) -c $^ -I $(HEADERS) -o $@

clean:
	@rm -rf $(DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'

fclean: clean
	@$(RM) $(RFLAGS) $(NAME)
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'

re : fclean all

exec: re
	./$(NAME)

.PHONY: all clean fclean re
