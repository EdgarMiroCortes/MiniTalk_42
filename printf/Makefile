SRCS			=	ft_digit.c\
					ft_hexnum.c\
					ft_printf.c\
					ft_ptr.c\
					ft_ui.c\
					utils.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= ft_printf.a

LIB_H			= ft_printf.h

all:			$(NAME)

%.o:		 	%.c $(LIB_H)
				$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re