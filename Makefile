NAME		=	push_swap

SRC_DIR		=	srcs/

OBJ_DIR         =       objs/
 
SRCS		=	List/push.c List/rotate.c List/rrotate.c List/swap.c \
				Main/main.c Main/init_stacks.c\
				Sort/sort.c Sort/utils.c Sort/utils2.c Sort/nb_move_a.c Sort/nb_move_b.c \
				Sort/nb_move_a_temp.c Sort/nb_move_b_temp.c Sort/nb_move_rr.c Sort/special_sort.c

vpath %.c $(SRC_DIR)

OBJS		=	$(patsubst %.c, $(OBJ_DIR)%.o, $(SRCS))

CC		=	cc

CFLAGS		=	-g3 -Wall -Wextra -Werror

LIB = libft/libft.a

INCLUDES = -I includes/ -I libft/includes/

RM		=	rm -f

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m
BOLD_START=\e[1m
BOLD_END=\e[0m

ifeq ($(debug), true)
	CFLAGS += -g3 -fsanitize=address,undefined
endif

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr "\r [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif

define PRINT_LOADING
	@printf "$(GREEN)Compiling libft["
	@for i in $(shell seq 0 10 100); do \
		printf "▓"; \
		sleep 0.1; \
	done
	@printf "] 100%%$(RESET)\n$(END)"
endef

all:                    ${NAME} libft
						$(ECHO) "$(GREEN)$(BOLD_START)${NAME} created$(BOLD_END)$(END)"



${NAME}:                 ${OBJS}
				@$(PRINT_LOADING)
				$(MAKE) --no-print-directory -C libft/
				$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(OBJS):                $(OBJ_DIR)%.o: %.c
				$(ECHO) "$(BLUE)Compiling: $@ $(END)"
				$(LIBFT)
				mkdir -p $(OBJ_DIR)
				mkdir -p objs/List/
				mkdir -p objs/Main/
				mkdir -p objs/Sort/
				$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			$(RM) -r $(OBJ_DIR)
			${RM} ${OBJS} ${BOBJS}
			@$(ECHO) "$(RED)Clean libft$(END)"
			$(MAKE) --no-print-directory clean -C ./libft/
			@$(ECHO) "$(GREEN)$(BOLD_START)Clean done$(BOLD_END)$(END)"

fclean:			clean
				${RM} ${NAME}
				@$(ECHO) "$(RED)Fclean libft$(END)"
				$(MAKE) --no-print-directory fclean -C ./libft/
				@$(ECHO) "$(GREEN)$(BOLD_START)Fclean done$(BOLD_END)$(END)"

re:				fclean all

.PHONY:			all clean fclean re
.SILENT: