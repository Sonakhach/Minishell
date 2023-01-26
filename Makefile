RED="\033[1;31m"
GREEN='\033[3;32m'
NONE='\033[0m'

NAME = minishell

CC = cc

CFLAGS =# -fsanitize=address  -Wall -Werror -Wextra

SRCS = $(wildcard *.c) #$(wildcard parsing_new/*.c) $(wildcard memory/*.c) $(wildcard builtin/*.c)*/

OBJS = $(patsubst %.c, %.o, $(SRCS))

INCLUDES = -Ilibft  -I./include

LINKERS	= -L./libft  -L./lib -lreadline

LINKERLIB = ./libft/libft.a

LIBFT = ./libft

RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# all: readline $(NAME) 
all: $(NAME) 
	
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@cp $(LINKERLIB) $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(LINKERS) $(INCLUDES) $(NAME) -o $(NAME)
	@echo $(NONE) $(GREEN)"       >Compiled< $(NAME)" $(NONE)

clean:
	@$(MAKE) clean -C $(LIBFT)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(RM) $(NAME)
	@echo $(NONE) $(RED)"       >Removed< $(NAME)" $(NONE)

re: fclean all

norm: clean
	norminette $(SRCS)

.PHONY: all clean fclean re
