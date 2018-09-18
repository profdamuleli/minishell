# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldamulel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/19 07:56:23 by ldamulel          #+#    #+#              #
#    Updated: 2017/09/28 13:06:07 by ldamulel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

RAWSRC = env_display.c \
		 env_dup.c \
		 execute_command.c \
		 found_in_path.c \
		 func_cd.c \
		 func_echo.c \
		 get_char.c \
		 get_input.c \
		 get_name.c \
		 get_path.c \
		 get_value.c \
		 launch_process.c \
		 minishell.c \
		 print_environ.c \
		 set_env.c \
		 unset_env.c \

SRC = $(RAWSRC:%=src/%)

OBJ = $(SRC:src/%.c=%.o)

LIBFT = ./libft/

FLAGS = #-Wall -Wextra -Werror \

all: $(NAME)

$(NAME): $(SRC)
	make -C $(LIBFT)
	@gcc -c $(FLAGS) $(SRC)
	gcc -o $(NAME) $(FLAGS) $(OBJ) -L$(LIBFT) -lft

clean:
	@rm -f $(OBJ)
	@cd $(LIBFT) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@cd $(LIBFT) && $(MAKE) fclean

re: fclean all
