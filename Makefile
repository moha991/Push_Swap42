# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfornah <mfornah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 09:35:58 by mfornah           #+#    #+#              #
#    Updated: 2023/07/30 16:49:01 by mfornah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## EXECUTABLE ##
NAME = push_swap

## COMPILATION ##
CC = gcc
CFLAGS = -Wall -Werror  -Wextra -g3 -fsanitize=address,undefined

## INCLUDE ##
LIBS_PATH = ./libft/srcs/libft.a


## VARIABLES ##
AR = @ar rcs
RM = @rm -f
MAKE_NOPRINT = $(MAKE) --no-print-directory -C
LINK = -L $(LIBS_PATH)


## SOURCE FILE ##
SRC = src/main.c src/Rev_Rotate.c src/Error_Handling.c src/Push.c\
	src/Rotate.c src/Stack.c src/Swap.c src/Stack_utils.c src/small_sort.c src/sort.c\
	src/find.c src/Stack_util2.c src/check.c src/free_error.c src/chunk.c\
	src/index.c 
OBJS = ${SRC:.c=.o}


## COLORS ##
END		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m


## RULES ##
all: libft $(NAME)

libft:
	@echo "$(NAME): $(BLUE)Generating... Just a minute$(RESET)"
	@make -sC ./libft/srcs
	@echo "$(NAME): $(GREEN)Done!$(RESET)"

%.o : %.c 
	@echo "${BLUE} ◎ $(YELLOW)Compiling   ${RED}→   $(WHITE)$< $(END)"	
	@$(CC) $(CFLAGS) -c -o $@ $< 
	
$(NAME) : libft $(OBJS) 
	@make -sC ./libft/srcs
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/srcs/libft.a
	clear
	@echo "$(GREEN)You Created $(NAME)$(END)"


## CLEANNING ##
clean:
	@$(RM) $(OBJS)
	@cd ./libft/srcs && make clean 
	@echo "$(GREEN)$(NAME): $(RED)→ $(BLUE) Cleaning... $(END)"
	@echo "$(GREEN)$(NAME): $(RED)→ $(YELLOW) the files(*.o) were deleted $(END)"

## REMOVING .O FILES AND .A FILES ##
fclean: clean
	$(RM) $(NAME) $(OBJS) $(LIBS_PATH)
	@make fclean -sC ./libft/srcs
	@echo "$(GREEN)$(NAME): $(RED) → $(BLUE)was deleted$(END)"
	
norm:
	-@norminette  $(SRCS_PATH)
	-@norminette  $(LIBS_PATH)

	

## REMOVING AND RUNNING ##
re: fclean all

.PHONY: all re clean fclean  norm



