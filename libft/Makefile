#
#	Makefile
#	by leaf
#	<loutre@courrier.dev>
#	18/05/18 17:16:17
#	31/05/31 17:20:38
#

MAKEFLAGS	+= --silent

NAME		= 	libft.a

CC			=	clang
FLAGS		=	-Wall -Wextra -Werror -c -fPIC

SRC_DIR 	= 	srcs/
INC_DIR 	= 	includes/
OBJ_DIR 	=	objs/

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
DIR			=	$(sort $(dir $(OBJS)))

SRC_BASE 	= \
ft_ptf/conv/conv_cs.c \
ft_ptf/conv/conv_diu.c \
ft_ptf/conv/conv_len.c \
ft_ptf/conv/conv_n.c \
ft_ptf/conv/conv_o.c \
ft_ptf/conv/conv_p.c \
ft_ptf/conv/conv_str.c \
ft_ptf/conv/conv_x.c \
ft_ptf/conv/conversions.c \
ft_ptf/conv/pf_itoa.c \
ft_ptf/core/buffer.c \
ft_ptf/core/format.c \
ft_ptf/core/ft_printf.c \
ft_ptf/parsing/parsing_flags.c \
ft_ptf/parsing/parsing_length.c \
ft_ptf/parsing/parsing_type.c \
ft_ptf/parsing/parsing_width_precision.c \
gnl/ft_gnl.c\
gnl/ft_gnl_utils.c\
lst/ft_lstadd_back.c\
lst/ft_lstadd_front.c\
lst/ft_lstclear.c\
lst/ft_lstdelone.c\
lst/ft_lstiter.c\
lst/ft_lstlast.c\
lst/ft_lstmap.c\
lst/ft_lstnew.c\
lst/ft_lstsize.c\
math/ft_pow.c\
mem/ft_bzero.c\
mem/ft_calloc.c\
mem/ft_memccpy.c\
mem/ft_memchr.c\
mem/ft_memcmp.c\
mem/ft_memcpy.c\
mem/ft_memmove.c\
mem/ft_memset.c\
norm/norm_obs.c\
output/ft_putchar_fd.c\
output/ft_putendl_fd.c\
output/ft_putnbr_fd.c\
output/ft_putstr_fd.c\
str/ft_atoi.c\
str/ft_isalnum.c\
str/ft_isalpha.c\
str/ft_isascii.c\
str/ft_isdigit.c\
str/ft_isspace.c\
str/ft_isprint.c\
str/ft_itoa.c\
str/ft_split.c\
str/ft_strchr.c\
str/ft_strcpy.c\
str/ft_strncpy.c\
str/ft_strncmp.c\
str/ft_strdup.c\
str/ft_strlcat.c\
str/ft_strlcpy.c\
str/ft_strjoin.c\
str/ft_strlen.c\
str/ft_strmapi.c\
str/ft_strnstr.c\
str/ft_strrchr.c\
str/ft_strtrim.c\
str/ft_substr.c\
str/ft_tolower.c\
str/ft_toupper.c

BLACK	=	\e[30m
RED		=	\e[31m
GREEN	=	\e[32m
YELLOW	=	\e[33m
BLUE	=	\e[34m
PURPLE	=	\e[35m
CYAN	=	\e[36m
END		=	\e[0m

all:		$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $@ $^
	@printf "\t$(PURPLE)Libft.a successfully created\n"

$(DIR):
	@mkdir -p $@

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(DIR)
	@$(CC) $(FLAGS) $< -o $@ -I $(INC_DIR)
	@printf "\t$(GREEN)Compiling [$(CYAN)$(notdir $^)$(GREEN)]$(END)\n";

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

re:			fclean
	@make all

.PHONY:		all clean fclean re
