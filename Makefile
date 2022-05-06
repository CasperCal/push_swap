CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

NAME		= push_swap
BONUS_NAME	= checker

SRC			= parsing_utils.c linked_list.c sorting_algo.c stackA_utils.c stackB_utils.c ft_split.c push_swap.c sort_big_utils.c big_sort.c
SRC_BONUS	= checker.c checker_utils.c minilib.c ft_split.c get_next_line.c get_next_line_utils.c linked_list.c parsing_utils.c stack2_utils.c stackA_utils_bonus.c stackB_utils_bonus.c
BONUS_DIR	= bonus/

OBJ_BONUS	= ${addprefix $(BONUS_DIR),$(SRC_BONUS:.c=.o)}
OBJ			= ${SRC:.c=.o}
RM			= rm -rf

all:	$(NAME)

bonus:	$(BONUS_NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@

$(BONUS_NAME):	$(OBJ_BONUS)
				$(CC) $(CLFAGS) $(OBJ_BONUS) -o $@
clean: 
		$(RM) $(OBJ)
		$(RM) $(OBJ_BONUS)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(BONUS_NAME)

re:		fclean all

.PHONY:	all clean fclean re