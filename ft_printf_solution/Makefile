NAME = libftprintf.a

CFILES = ft_printf.c \
		 ft_printf_utils.c \
		 ft_printf_utils2.c

OFILES = $(CFILES:.c=.o)

CC = cc

AR = ar -rcs

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
		 $(CC) $(CFLAGS) -c $(CFILES)
		 $(AR) $(NAME) $(OFILES)

clean:
	  $(RM) $(OFILES)

fclean: clean
	    $(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re

