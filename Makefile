# Compiler dan flags dasar
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Jika ada folder 'include', tambahkan -Iinclude
ifneq ($(wildcard include/.),)
    CFLAGS += -Iinclude
endif

# Folder
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Program utama (bisa diubah via CLA, default: main)
TARGET ?= program1

# Output binary
BINARY = $(BIN_DIR)/$(TARGET)

# File sumber dan object
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Target utama
$(BINARY): $(OBJ_DIR)/$(TARGET).o $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Kompilasi program utama (TARGET.c -> TARGET.o)
$(OBJ_DIR)/$(TARGET).o: $(TARGET).c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Kompilasi file src/*.c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

# Membuat direktori jika tidak ada
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Bersihkan file bin dan obj
clean: clean-bin clean-obj

# Hapus hanya file bin
clean-bin:
	rm -rf $(BIN_DIR)/*

# Hapus hanya file obj
clean-obj:
	rm -rf $(OBJ_DIR)/*.o