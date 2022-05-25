NAME = push_swap
CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
SRCS = select_algo.c \
       already_sorted.c \
       compare_algo.c \
       algo_assets2.c \
       cmd_handler.c \
       ft_init_rank.c \
       print_cmds.c \
       swap.c \
       algo_assets3.c \
       condition_swap.c \
       ft_nbnew.c \
       push.c \
       reverse_rotate.c \
       tri_base.c \
       algo_assets.c \
       freer.c \
       itoa_base.c \
       main.c \
       push_swap.c \
       rotate.c \
       tri_insertion.c \
       sort3_5.c \
       ft_atoiverif.c \
       cmds_size.c \
       algo_call.c \

INC = includes/
LIBFT = ./libft
OBJS = ${SRCS:.c=.o}

$(NAME): ${OBJS}
		$(MAKE) -C ${LIBFT}
	 	${CC} ${FLAGS} ${OBJS} -L ${LIBFT} -lft -o ${NAME}

all:	 ${NAME}

clean:	
	make clean -C ${LIBFT}
	 ${RM} ${OBJS}

fclean:	clean 
	make fclean -C ${LIBFT}
	 ${RM} -rf ${NAME}

re: fclean all

.PHONY: clean all fclean re
