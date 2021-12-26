# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/07 21:04:42 by mraasvel      #+#    #+#                  #
#    Updated: 2021/03/08 15:21:36 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include config.mk

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(DEPS)
	ar rc $@ $(OBJ)
$(OBJDIR)/%.o: %.s $(DEPS) | $(OBJDIR)
	$(ASM) $(ASMFLAGS) -o $@ $<

$(OBJDIR):
	mkdir -p $@

.PHONY: clean fclean re
clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean
	$(MAKE) all

.PHONY: bonus
bonus:
	$(MAKE) BONUS=1
