CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap

SRC		= parsing_utils.c linked_list.c sorting_algo.c stackA_utils.c stackB_utils.c ft_split.c push_swap.c sort_big_utils.c big_sort.c

OBJ		= ${SRC:.c=.o}
RM		= rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@

clean: 
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re