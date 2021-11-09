NAME = libft.a

SRCS = 	ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memchr.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strncmp.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_split.c ft_split_utils.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		get_next_line.c

OBJS = $(SRCS:.c=.o)

INCLUDE = -I./

HEADER = libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

$(NAME) :	${OBJS}
	ar rcs ${NAME} $?


%.o	: 	%.c ${HEADER}
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re	: fclean all

.PHONY: all clean fclean re
