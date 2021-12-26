# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    config.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/07 21:14:29 by mraasvel      #+#    #+#                  #
#    Updated: 2021/03/08 15:18:21 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Variables are defined here

NAME = libasm.a
SRC =	ft_strlen.s	\
		ft_strcpy.s	\
		ft_strcmp.s	\
		ft_write.s	\
		ft_read.s	\
		ft_strdup.s
OBJ = $(addprefix $(OBJDIR)/, $(SRC:.s=.o))
HEADER = libasm.h
DEPS = $(HEADER)

# Bonus
BONUS_SRC =	ft_list_push_front.s	\
			ft_list_size.s			\
			ft_list_sort.s			\
			ft_list_remove_if.s		\
			ft_atoi_base.s
BONUS_OBJ = $(addprefix $(OBJDIR)/, $(BONUS_SRC:.s=.o))
ifdef BONUS
SRC += $(BONUS_SRC)
OBJ += $(BONUS_OBJ)
endif

# Directories
OBJDIR = obj

# Handle OS
OS_NAME = $(shell uname -s)

ifeq ($(OS_NAME),Linux)
SRCDIR = src_linux
ASMFLAGS = -f elf64

else

SRCDIR = src_mac
ASMFLAGS = -f macho64
endif

# Where to find file types
vpath %.s $(SRCDIR)
vpath %.o $(OBJDIR)

#Compilation
ASM = nasm
