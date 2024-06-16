NAME		=	push_swap


SRC_DIR		=	srcs/

OBJ_DIR         =       objs/
 
SRCS		=	List/push.c List/rotate.c List/rrotate.c List/swap.c \
				Main/main.c \
				Sort/sort.c 

vpath %.c $(SRC_DIR)

OBJS		=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

CC		=	cc

CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	= 	-I/includes/push_swap.h

RM		=	rm -f

ifeq ($(debug), true)
	CFLAGS += -g3 -fsanitize=address,undefined
endif

all:                    ${NAME}
						@$(ECHO) All done

${NAME}:                ${OBJS}
				$(MAKE) -C ./libft/
				$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME) 
				

$(OBJS):                $(OBJ_DIR)%.o: %.c
				mkdir -p $(OBJ_DIR)
				mkdir -p objs/List/
				mkdir -p objs/Main/
				mkdir -p objs/Sort/
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

clean:
			$(RM) -r $(OBJ_DIR)
			${RM} ${OBJS} ${BOBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
