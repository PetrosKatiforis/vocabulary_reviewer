# Build Configuration
EXE_NAME = executable
BUILD_DIR = build
SOURCE_DIR = src

SOURCES = $(notdir $(wildcard $(SOURCE_DIR)/*.c))
OBJECTS = $(SOURCES:%.c=$(BUILD_DIR)/%.o)


.PHONY: build clean run

# Compile a single source file into an object file
$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c
	@gcc -c $< -o $@

	@echo "Compiling $<..."

build: $(OBJECTS)
	@gcc $(OBJECTS) -o $(BUILD_DIR)/$(EXE_NAME)

	@echo "Build was completed"

# Build and run executable
run:
	@$(MAKE) build

	clear	

	@./$(BUILD_DIR)/$(EXE_NAME)

clean:
	rm $(BUILD_DIR)/$(EXE_NAME)
	rm -rf $(BUILD_DIR)/*.o


