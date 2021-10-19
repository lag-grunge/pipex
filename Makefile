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

LIBFT = libft.a

LIB_DIR = ./libft

INCLUDE = -I${LIB_DIR} -I./includes

LIBRARIES = -L${LIB_DIR} -lft

CFLAGS = -g -Wall -Wextra -Werror

${OBJS_DIR}/%.o : ${SRCS_DIR}/%.c
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

${OBJS_REQ_DIR}/%.o : ${SRCS_REQ_DIR}/%.c
	$(CC) ${CFLAGS} ${INCLUDE} -c $< -o $@

all : ${LIBFT} ${NAME}

${LIBFT} : ${LIB_DIR}
	@make -C $<

${NAME} : ${OBJS_REQ} ${OBJS_CMN}
		$(CC) ${CFLAGS} $^ ${LIBRARIES} -o $@
		@rm -rf ${OBJS_OUT}

bonus	:
	make BONUS=1 all

${OBJS_REQ} : | ${DIRS} ${OBJS_CMN}

${DIRS} :
	mkdir -p ${OBJS_DIR}
	mkdir -p ${OBJS_B_DIR}
	mkdir -p ${OBJS_MAND_DIR}

clean :
	@make clean -C ${LIB_DIR}
	rm -f ${OBJS_REQ} ${OBJS_CMN}

fclean : clean
	@rm -f ${LIB_DIR}/${LIBFT}
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
