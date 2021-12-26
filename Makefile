# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/07 21:02:21 by mraasvel      #+#    #+#                  #
#    Updated: 2021/03/10 12:47:52 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include config.mk

NAME = a.out
SRC = $(shell find $(SRCDIRS) -maxdepth 1 -name "*.c" -type f -exec basename {} \;)
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEADERS = $(shell find $(IDIR) -name "*.h" -type f)
DEPS = $(HEADERS) Makefile

ifdef BONUS
LIBASM_RULE = bonus
BONUS_DIR = $(SRCDIR)/bonus $(SRCDIR)/bonus/function_refs $(SRCDIR)/bonus/bonus_testers
else
BONUS_DIR = $(SRCDIR)/non_bonus
endif

SRCDIRS += $(BONUS_DIR)

#DIRS
SRCDIR = src
SRCDIRS += $(SRCDIR) $(SRCDIR)/testers
OBJDIR = obj
IDIR = includes

vpath %.c $(SRCDIRS)
vpath %.o $(OBJDIR)
vpath %.h $(IDIR)

# Compilation
CC = gcc
DFLAGS = -g -O0 -fsanitize=address
CFLAGS = -Wall -Wextra
IFLAGS = -I$(IDIR)
LIBFLAGS =
LIBFLAGS += $(LIBASM_FLAG)

ifdef DEBUG
CFLAGS += $(DFLAGS)
else
CFLAGS += -O3
endif

LIBASMOUT = libasm_out.txt
STDLIBOUT = stdlib_out.txt
OUTPUT_FILES = $(LIBASMOUT) $(STDLIBOUT)


.PHONY: all
all:
	$(MAKE) -j4 $(LIBASM_RULE) -C $(LIBASM_PATH)
	$(MAKE) -j4 $(NAME)

$(NAME): $(OBJ) $(LIBASM)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAGS)
$(OBJDIR)/%.o: %.c $(DEPS) | $(OBJDIR)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean fclean re
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(OUTPUT_FILES)
	$(MAKE) clean -C $(LIBASM_PATH)
fclean: clean
	$(MAKE) fclean -C $(LIBASM_PATH)
	rm -f $(NAME)
re: fclean
	$(MAKE) -C $(LIBASM_PATH)
	$(MAKE) all

.PHONY: debug bonus
debug:
	$(MAKE) re DEBUG=1
bonus:
	$(MAKE) BONUS=1


# execution rules:
.PHONY: run_bonus run run_tests
run_bonus:
	$(MAKE) -j4 bonus
	$(MAKE) run_tests
run:
	$(MAKE) -j4 all
	$(MAKE) run_tests
run_example:
	$(MAKE) -j4 bonus
	./$(NAME) example
run_tests:
	./$(NAME) 0 > $(LIBASMOUT)
	./$(NAME) 1 > $(STDLIBOUT)
