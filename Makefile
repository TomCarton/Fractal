# Makefile

TARGET := fractal

OBJ_DIR := obj

C_FILES := $(wildcard sources/*.c)
OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(notdir $(C_FILES:.c=.o)))

CC=clang
CC_FLAGS = -Wall -O3


all: $(OBJ_FILES) libraries/image/libImage.a
	$(CC) $(CC_FLAGS) libraries/image/libImage.a $^ -o $(TARGET)

libraries/image/libImage.a:
	cd libraries/image && $(MAKE) libImage.a
	cd ../..

$(OBJ_DIR)/%.o: sources/%.c
	@echo Compile "$@"...
	$(CC) $(CC_FLAGS) -c $^ -o $@

$(filter %.o,$(C_FILES)): %.o: %.c %.h
	@echo Compile "$<" to "$@"...
	$(CC) $(CC_FLAGS) -c $< -o $@


$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)


.PHONY: clean
clean:
	cd libraries/image && $(MAKE) clean
	rm -rf $(OBJ_DIR)
	rm $(TARGET)


.PHONY: info
info:
	@echo sources: $(C_FILES)
	@echo objects: $(OBJ_FILES)
