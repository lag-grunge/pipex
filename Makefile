NAME = pipex

SRCS = pipex.c parser.c
SRCS_B = pipex_bonus.c parser.c redirect.c

OBJS = ${SRCS:.c=.o}
ifdef BONUS
OBJS = ${SRCS_B:.c=.o}
endif

LIBFT = libft.a

LIB_DIR = ./libft

INCLUDE = -I${LIB_DIR} -I.

LIBRARIES = -L${LIB_DIR} -lft

CFLAGS = -g -Wall -Wextra -Werror

all : ${LIBFT} ${NAME}

${LIBFT} : ${LIB_DIR}
	make -C $<

${NAME} : ${OBJS}
		$(CC) ${CFLAGS} ${OBJS} ${LIBRARIES} -o $@

bonus	:
	make BONUS=1 all

%.o : %.c
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

clean :
	make clean -C ${LIB_DIR}
	rm -f ${OBJS}

fclean : clean
	rm -f ${LIB_DIR}/${LIBFT}
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
