CC = gcc
CFLAGS = -Wall -O2
SRC_DIR = src
OUTPUT_DIR = output
BIN_DIR = bin
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BIN_DIR)/%.o)
EXECUTABLE = $(BIN_DIR)/image_generator
.PHONY: all prepare run clean show_info
all: prepare $(EXECUTABLE) run show_info
prepare:
	@mkdir -p $(BIN_DIR) $(OUTPUT_DIR)
	@echo '[PREP] Carpetas creadas'
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@echo '[CC] Compilando...'
	@$(CC) $(CFLAGS) -c $< -o $@
$(EXECUTABLE): $(OBJECTS)
	@echo '[LD] Enlazando...'
	@$(CC) $(CFLAGS) $(OBJECTS) -ljpeg -o $@
run: $(EXECUTABLE)
	@echo '[RUN] Ejecutando...'
	@./$(EXECUTABLE)
show_info:
	@echo '-----------------------------------'
	@echo 'Compilacion exitosa'
	@echo '-----------------------------------'
clean:
	@rm -rf $(BIN_DIR) $(OUTPUT_DIR)
