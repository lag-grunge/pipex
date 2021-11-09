NAME = pipex

SRCS = pipex.c
SRCS_B = pipex_bonus.c
SRCS_CMN = parser.c utils.c here_doc.c
SRCS_DIR = ./srcs
SRCS_MAND_DIR = ./srcs/mand
SRCS_B_DIR = ./srcs/bonus

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}
OBJS_CMN = $(addprefix ${OBJS_DIR}/,${SRCS_CMN:.c=.o})
OBJS_MAND_DIR = ./objs/mand
OBJS_B_DIR = ./objs/bonus
OBJS_DIR = ./objs
DIRS = ${OBJS_DIR} ${OBJS_MAND_DIR} ${OBJS_B_DIR}
ifndef BONUS
OBJS_REQ = $(addprefix ${OBJS_MAND_DIR}/, ${OBJS})
OBJS_REQ_DIR = ${OBJS_MAND_DIR}
SRCS_REQ_DIR = ${SRCS_MAND_DIR}
OBJS_OUT = $(addprefix ${OBJS_B_DIR}/,${OBJS_B})
else
OBJS_REQ = $(addprefix ${OBJS_B_DIR}/, ${OBJS_B})
OBJS_REQ_DIR = ${OBJS_B_DIR}
SRCS_REQ_DIR = ${SRCS_B_DIR}
OBJS_OUT = $(addprefix ${OBJS_MAND_DIR}/,${OBJS})
endif

LIB_DIR = ./libft

LIBFT = ${LIB_DIR}/libft.a

INCLUDE = -I${LIB_DIR} -I./includes

HEADERS = pipex.h ${LIB_DIR}/libft.h

LIBRARIES =  -lft

CFLAGS = -g -Wall -Wextra -Werror -MMD

LDFLAGS = -L${LIB_DIR} -fsanitize=address

DEPS := ${OBJS_REQ:.o=.d} ${OBJS_CMN:.o=.d}

${OBJS_DIR}/%.o : ${SRCS_DIR}/%.c
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJS_REQ_DIR}/%.o : ${SRCS_REQ_DIR}/%.c
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

all : ${NAME}

${NAME} : ${OBJS_REQ} ${OBJS_CMN} ${LIBFT}
		$(CC) ${LDFLAGS} ${OBJS_REQ} ${OBJS_CMN} ${LIBRARIES} -o $@
		@rm -rf ${OBJS_OUT}

bonus	:
	make BONUS=1 all

${OBJS_REQ} ${OBJS_CMN} : | ${DIRS}

${DIRS} :
	mkdir -p ${OBJS_DIR}
	mkdir -p ${OBJS_B_DIR}
	mkdir -p ${OBJS_MAND_DIR}


${LIBFT} : libft ;

-include ${DEPS}

.PHONY : all clean fclean re libft

clean :
	@make clean -C ${LIB_DIR}
	rm -f ${OBJS_REQ} ${OBJS_CMN} ${DEPS}

fclean : clean
	@rm -f ${LIBFT}
	rm -f ${NAME}

re : fclean all

libft :
	@make -C ${LIB_DIR}
