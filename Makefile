NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

norm:
	norminette $(SRCS) *.h

re: fclean all

.PHONY: all clean fclean re norm