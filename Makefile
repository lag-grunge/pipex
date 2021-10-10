NAME = pipex

SRCS = pipex.c parser.c

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

LIB_DIR = ./libft

INCLUDE = -I${LIB_DIR} -I.

LIBRARIES = -L${LIB_DIR} -lft

CFLAGS = -g -Wall -Wextra -Werror

all : ${LIBFT} ${NAME} ${NAME2}

${LIBFT} : ${LIB_DIR}
	make -C $<

${NAME} : ${OBJS}
	$(CC) ${CFLAGS} ${LIBRARIES} $^ -o $@

%.o : %.c
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re

