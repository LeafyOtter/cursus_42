#
#	Makefile
#	by fire
#	<loutre@courrier.dev>
#	24/07/21 14:05:08
#	26/09/21 15:44:10
#

MAKEFLAGS	+=	--silent

NAME		=	push_swap

#CC			=	clang
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g

SRC_DIR		=	srcs/
INC_DIR		=	-I./includes/
OBJ_DIR 	=	objs/

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJS)))

SRC_BASE 	= \
lst_utils.c \
main.c \
markup.c \
parsing_utils.c \
push.c \
presort.c \
quicksort.c \
rotate.c \
sort.c \
sort_small.c \
sort_utils.c \
swap.c \
utils.c

BLACK	=	\e[30m
RED		=	\e[31m
GREEN	=	\e[32m
YELLOW	=	\e[33m
BLUE	=	\e[34m
PURPLE	=	\e[35m
CYAN	=	\e[36m
END		=	\e[0m

all:	$(NAME)

$(NAME): 	$(OBJS)
	@$(CC) $(INC_DIR) $(FLAGS) -o $@ $(OBJS) $(LIB)
	@printf "\t$(PURPLE)$(NAME) created\n$(END)"
	@printf "[1]    4221 segmentation fault (core dumped)  ./push_swap\n"
#	@printf "make: *** [objs/ps.o] Error 1\n"

$(DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(DIR)
	@printf "\t$(GREEN)Compiling [$(END)";
	$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR)
	@printf "$(CYAN)$(notdir $^)$(GREEN)]$(END)\n";

	#@$(MAKE) -C $(LIB_DIR) clean
clean:
	@if [ -d $(OBJ_DIR) ]; \
		then \
		printf "\t$(YELLOW)Object files successfully deleted\n$(END)"; \
		rm -rf $(OBJ_DIR); \
		fi;

fclean:		clean
	@if [ -e $(NAME) ]; \
		then \
		printf "\t$(YELLOW)$(NAME) successfully deleted\n$(END)"; \
		rm -rf $(NAME); \
		fi;

bonus: all

re:			fclean
	@$(MAKE) all

.PHONY:		all clean fclean re
