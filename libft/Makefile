NAME = libft.a
INCDIR = includes
OBJDIR = obj
SRCS = \
	src/char/ft_isalnum.c \
	src/char/ft_isalpha.c \
	src/char/ft_isascii.c \
	src/char/ft_isdigit.c \
	src/char/ft_tolower.c \
	src/char/ft_toupper.c \
	src/char/ft_isprint.c \
	src/char/ft_ispace.c \
	src/char/ft_not_printable.c \
	\
	src/string/ft_strlen.c \
	src/string/ft_strchr.c \
	src/string/ft_strrchr.c \
	src/string/ft_strncmp.c \
	src/string/ft_strlcpy.c \
	src/string/ft_strlcat.c \
	src/string/ft_strdup.c \
	src/string/ft_substr.c \
	src/string/ft_strjoin.c \
	src/string/ft_strtrim.c \
	src/string/ft_split.c \
	src/string/ft_strmapi.c \
	src/string/ft_striteri.c \
	src/string/ft_atoi.c \
	src/string/ft_itoa.c \
	src/string/ft_strnstr.c \
	src/string/ft_strjoin_and_free.c \
	\
	src/mem/ft_memset.c \
	src/mem/ft_bzero.c \
	src/mem/ft_memcpy.c \
	src/mem/ft_memmove.c \
	src/mem/ft_memchr.c \
	src/mem/ft_memcmp.c \
	src/mem/ft_calloc.c \
	\
	src/fd/ft_putchar_fd.c \
	src/fd/ft_putstr_fd.c \
	src/fd/ft_putendl_fd.c \
	src/fd/ft_putnbr_fd.c \
	\
	src/list/ft_lstnew.c \
	src/list/ft_lstadd_front.c \
	src/list/ft_lstsize.c \
	src/list/ft_lstlast.c \
	src/list/ft_lstadd_back.c \
	src/list/ft_lstdelone.c \
	src/list/ft_lstclear.c \
	src/list/ft_lstiter.c \
	src/list/ft_lstmap.c \
	\
	src/gnl/get_next_line.c \
	\
	
OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)
DEBUG = 
CC =	cc
CFLAGS =	-Wall -Wextra -Werror -I$(INCDIR) $(DEBUG)

clear:
	@$(MAKE) -s all
		@echo "                       .,,uod8B8bou,,."
	@echo "              ..,uod8BBBBBBBBBBBBBBBBRPFT?l!i:."
	@echo "         ,=m8BBBBBBBBBBBBBBBRPFT?!||||||||||||||"
	@echo "         !...:!TVBBBRPFT||||||||||!!^^\"\"'  |||||"
	@echo "         !.........||||                     ||||"
	@echo "         !.........||||                     ||||"
	@echo "         !.........||||                     ||||"
	@echo "         !.........||||                     ||||"
	@printf "         !.........|||| !!\033[31mCompiling libft...\033[0m||||\n"
	@printf "         !.........||||    \033[31m[ 25%%] foo.o\033[0m     ||||\n"
	@printf "         !.........||||    \033[33m[ 50%%] bar.o\033[0m     ||||\n"
	@printf "         !.........||||    \033[33m[ 75%%] baz.o\033[0m     ||||\n"
	@printf "         !.........||||    \033[32m[100%%] done!\033[0m     ||||\n"
	@echo "         !.........||||                     ||||"
	@echo "         !.........||||                     ||||"
	@echo "         !.........||||                     ||||"
	@echo "         !.........||||                    ,||||"
	@echo "          .;.......||||               _.-!!|||||"
	@echo "   .,uodWBBBBb.....||||       _.-!!|||||||||!:'"
	@echo "!YBBBBBBBBBBBBBBb..!|||:..-!!|||||||!iof68BBBBBb...."
	@echo "!..YBBBBBBBBBBBBBBb!!||||||||!iof68BBBBBBRPFT?!::   ``."
	@echo "!....YBBBBBBBBBBBBBBbaaitf68BBBBBBRPFT?!:::::::::     ``."
	@echo "!......YBBBBBBBBBBBBBBBBBBBRPFT?!::::::;:!^\"``;:::       ``."
	@echo "!........YBBBBBBBBBBRPFT?!::::::::::^''...::::::;         iBBbo."
	@echo "``..........YBRPFT?!::::::::::::::::::::::::;iof68bo.      WBBBBbo."
	@echo "  \`..........:::::::::::::::::::::::;iof688888888888b.     \`YBBBP^'"
	@echo "    \`........::::::::::::::::;iof688888888888888888888b.     \`"
	@echo "      \`......:::::::::;iof688888888888888888888888888888b."
	@echo "        \`....:::;iof688888888888888888888888888888888899fT!"
	@echo "          \`..::!8888888888888888888888888888888899fT|!^\"'"
	@echo "            \`' !!988888888888888888888888899fT|!^\"'"
	@echo "                \`!!8888888888888888899fT|!^\"'"
	@echo "                  \`!988888888899fT|!^\"'"
	@echo "                    \`!9899fT|!^\"'"

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
