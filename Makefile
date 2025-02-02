NAME	= push_swap
CC 		= cc
CFLAGS	= -Wextra -Wall -Werror

SRCS	= extra.c  extra_2.c error.c find.c ft_atoi.c \
		ft_split.c handle_sorting.c push.c rotate.c swap.c \
		reverse_rotate.c push_swap.c radix.c

OBJ = $(SRCS:.c=.o)
OBJDIR = obj/
OBJS = $(addprefix $(OBJDIR), $(OBJ))

all: $(NAME)

$(NAME): $(OBJR) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
