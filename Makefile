NAME		=	push_swap


SRC_DIR		=	srcs/

OBJ_DIR         =       objs/
 
SRCS		=	List/push.c List/rotate.c List/rrotate.c List/swap.c \
				Main/main.c \
				Sort/sort.c 

vpath %.c $(SRC_DIR)

OBJS		=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

CC		=	cc

CFLAGS		=	 -Wall -Wextra -Werror

INCLUDES	= 	-I/includes/push_swap.h

RM		=	rm -f

ifeq ($(debug), true)
	CFLAGS += -g3 -fsanitize=address,undefined
endif

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr " [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif

all:                    ${NAME}
						@$(ECHO) All done

${NAME}:                ${OBJS}
				$(MAKE) -C ./libft/
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES)
				

$(OBJS):                $(OBJ_DIR)%.o: %.c
						$(ECHO) Compiling $@
				mkdir -p $(OBJ_DIR)
				mkdir -p objs/List/
				mkdir -p objs/Main/
				mkdir -p objs/Sort/
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
			$(RM) -r $(OBJ_DIR)
			${RM} ${OBJS} ${BOBJS}
			$(MAKE) clean -C ./libft/
			@$(ECHO) Clean done

fclean:			clean
				${RM} ${NAME}
				@$(ECHO) Fclean done

re:				fclean all

.PHONY:			all clean fclean re
.SILENT:
