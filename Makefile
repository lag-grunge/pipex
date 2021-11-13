NAME = pipex

SRCS = pipex.c
SRCS_CMN = parser.c utils.c here_doc.c
SRCS_DIR = ./srcs
SRCS_MAND_DIR = ${SRCS_DIR}/mand
SRCS_B_DIR = ${SRCS_DIR}/bonus

OBJS = ${SRCS:.c=.o}
OBJS_DIR = ./objs
OBJS_CMN = $(addprefix ${OBJS_DIR}/,${SRCS_CMN:.c=.o})
DIRS = ${OBJS_DIR}

LIB_DIR = ./libft
LIBFT = ${LIB_DIR}/libft.a
INCLUDE = -I${LIB_DIR} -I./includes
LIBRARIES =  -lft
CFLAGS = -Wall -Wextra -Werror -MMD
DEPS := ${OBJS:.o=.d} ${OBJS_CMN:.o=.d}

all bonus : ${OBJS_CMN} ${LIBFT}

all :
	make -C ${SRCS_MAND_DIR}

bonus	:
	make -C ${SRCS_B_DIR}

${DIRS} :
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}/%.o : ${SRCS_DIR}/%.c | ${DIRS}
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

${LIBFT} : libft ;

-include ${DEPS}

.PHONY : all clean fclean re libft

clean :
	@make clean -C ${LIB_DIR}
#	rm -f ${OBJS} ${OBJS_CMN} ${DEPS}
	rm -rf ${OBJS_DIR}

fclean : clean
	@rm -f ${LIBFT}
	rm -f ${NAME}

re : fclean all

libft :
	@make -C ${LIB_DIR}
