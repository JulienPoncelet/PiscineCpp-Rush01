NAME = ft_gkrellm

DIRSRC = ./srcs/
DIROBJ = ./.obj/

SRC = 	main.cpp\
		AModuleSimple.cpp\
		ModuleHostname.cpp\
		ModuleOSInfo.cpp\
		ModuleTime.cpp\
		ModuleCPU.cpp\
		ModuleRAM.cpp

SRC += 	NcursesDisplay.cpp\
		NWindow.cpp \
		Position.cpp

OBJ = $(SRC:.cpp=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

HEADERS = ./headers/

CFLAGS = -Wall -Werror -Wextra -g
CC = /usr/local/bin/g++

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
