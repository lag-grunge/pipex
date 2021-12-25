NAME = ../../pipex

SRCS = pipex.c
SRCS_CMN = parser.c utils.c here_doc.c

OBJS = $(addprefix ${OBJS_DIR}/,${SRCS:.c=.o})
OBJS_DIR = ../../objs
OBJS_CMN = $(addprefix ${OBJS_DIR}/,${SRCS_CMN:.c=.o})
DEPS = ${OBJS:.o=.d} ${OBJS_CMN:.o=.d}

LIB_DIR = ../../libft
LIBRARIES =  -lft
CFLAGS := -g -Wall -Wextra -Werror -MMD
INCLUDE = -I${LIB_DIR} -I../../includes
CFLAGS += ${INCLUDE}
LDFLAGS = -L${LIB_DIR}

		
all : $(shell touch ${SRCS}) ${NAME}

${NAME} : ${OBJS} ${OBJS_CMN}
		$(CC) ${LDFLAGS} $^ ${LIBRARIES} -o $@

${OBJS} : ${SRCS}
		$(CC) ${CFLAGS} -c ${SRCS} -o $@

-include ${DEPS}

.PHONY : all
