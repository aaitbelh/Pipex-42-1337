HEADER= pipex.h
NAME = pipex

SRCS = ft_check_acs.c ft_perror.c ft_split.c \
		ft_strjoin.c ft_strlen.c ft_strncmp.c pipex.c\

OBJS = $(SRCS:.c=.o)

CC = GCC
FLAGS = -Wall -Werror -Wextra

all : $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all