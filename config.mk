# Libasm configuration
LIBASM_PATH = ./libasm
LIBASM_NAME = libasm.a
LIBASM_HEADER = libasm.h
LIBASM_FLAG = -L$(LIBASM_PATH) -lasm
LIBASM_RULE = all

LIBASM = $(LIBASM_PATH)/$(LIBASM_NAME)
