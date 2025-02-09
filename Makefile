##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC 	?=	gcc

SRC	=	src/main.c					\
		src/organized.c				\
		src/add.c					\
		src/disp.c					\
		src/del.c					\
		src/sort.c					\
		src/copy_list.c				\
		src/merge_list.c			\

OBJ     =   $(SRC:.c=.o)

NAME    =	organized

LIB	=	make -C lib/my/

CFLAGS += -Wall -Wextra

CPPFLAGS += -iquote include/

all :	$(NAME)

$(NAME):	$(OBJ)
	$(LIB)
	$(CC) -o $(NAME) $(CPPFLAGS) $(CFLAGS) $(SRC) -L lib/my/ -lmy -lshell

clean:
	make clean -C lib/my/
	$(RM) $(OBJ)
	$(RM) coding-style*
	$(RM) *~
	$(RM) *#
	$(RM) *.o
	$(RM) src/*~
	$(RM) src/#*
	$(RM) include/*#
	$(RM) include/*~
fclean: clean
	make fclean -C lib/my/
	$(RM) $(NAME)
	$(RM) ./lib/my/libmy.a
	$(RM) libmy.a

re:	fclean all

.PHONY: all clean fclean re
