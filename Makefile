NAME = pipex

SRCS = pipex.c parser.c
SRCS_B = pipex_bonus.c parser.c

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}

LIBFT = libft.a

LIB_DIR = ./libft

INCLUDE = -I${LIB_DIR} -I.

LIBRARIES = -L${LIB_DIR} -lft

CFLAGS = -g -Wall -Wextra -Werror

all : ${LIBFT} ${NAME}

${LIBFT} : ${LIB_DIR}
	make -C $<

${NAME} : ${OBJS} ${OBJS_B}
	ifeq (BONUS, 1)
		$(CC) ${CFLAGS} ${LIBRARIES} ${OBJS_B} -o $@
	else
		$(CC) ${CFLAGS} ${LIBRARIES} ${OBJS} -o $@

bonus	:
	make all -C .

%.o : %.c
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re

