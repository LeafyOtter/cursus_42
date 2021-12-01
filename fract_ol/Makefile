#
#	Makefile
#	by leaf
#	<loutre@courrier.dev>
#	15/06/15 15:14:22
#	11/07/21 19:43:16
#

MAKEFLAGS	+=	--silent

NAME		=	fractol

CC			=	clang
FLAGS		=	-Ofast -Wall -Wextra -Werror
LINKFLAGS	=	-lXext -lX11 -lm -lbsd -o

SRC_DIR		=	srcs/
INC_DIR		=	-I./includes/
OBJ_DIR 	=	objs/

LIB_DIR		=	libft
LIBFT		=	libft.a
MLX_DIR		=	minilibx-linux
MLX			=	libmlx.a
LIB			=	$(LIB_DIR)/$(LIBFT) $(MLX_DIR)/$(MLX)

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJS)))

SRC_BASE 	= \
helper.c \
main.c \
parsing.c\
julia.c \
mandel.c \
mlx_utils.c \
math_utils.c

BLACK	=	\e[30m
RED		=	\e[31m
GREEN	=	\e[32m
YELLOW	=	\e[33m
BLUE	=	\e[34m
PURPLE	=	\e[35m
CYAN	=	\e[36m
END		=	\e[0m

all:	$(NAME)

bonus: fclean all

$(LIBFT):
	@$(MAKE) -C $(LIB_DIR) all --no-print-directory
	@cp -u $(LIB_DIR)/includes/libft.h includes/libft.h

$(MLX):
	@if [ ! -e $(MLX_DIR)/$(MLX) ]; \
		then \
		$(MAKE) -C $(MLX_DIR) --no-print-directory; \
		fi;
	@if [ ! -e includes/mlx.h ]; \
		then \
		cp $(MLX_DIR)/mlx.h includes/mlx.h; \
		fi;

$(NAME): 	$(MLX) $(LIBFT) $(OBJS)
	@$(CC) $(INC_DIR) -fsanitize=address -g $(LINKFLAGS) $@ $(OBJS) $(LIB);
	@printf "\t$(PURPLE)$(NAME) created\n$(END)"

$(DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(DIR)
	@printf "\t$(GREEN)Compiling [$(END)";
	@$(CC) -c $(FLAGS) $< -o $@ $(INC_DIR);
	@printf "$(CYAN)$(notdir $^)$(GREEN)]$(END)\n";

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@if [ -d $(OBJ_DIR) ]; \
		then \
		printf "\t$(YELLOW)Object files successfully deleted\n$(END)"; \
		rm -rf $(OBJ_DIR); \
		fi;

fclean:		clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@if [ -e $(NAME) ]; \
		then \
		printf "\t$(YELLOW)$(NAME) successfully deleted\n$(END)"; \
		rm -rf $(NAME); \
		fi;
	@if [ -e includes/libft.h ]; \
		then \
		rm -rf includes/libft.h; \
		printf "\t$(YELLOW)libft.h successfully deleted\n$(END)"; \
		fi;

libclean:	fclean
	@if [ -e $(MLX_DIR)/$(MLX) ]; \
		then \
		$(MAKE) -C $(MLX_DIR) clean; \
		printf "\t$(YELLOW)$(MLX) successfully deleted\n$(END)"; \
		fi;
	@if [ -e includes/mlx.h ]; \
		then \
		rm -rf includes/mlx.h; \
		printf "\t$(YELLOW)mlx.h successfully deleted\n$(END)"; \
		fi;

bonus:		all

re:			fclean $(MLX)
	@$(MAKE) -C $(LIB_DIR) re
	@$(MAKE) all

.PHONY:		libft all clean fclean libclean re
