# ------------------ Remove this the following comment to run and debug on Mac ------------------ 

# SRC_DIR = src
# BUILD_DIR = build/debug
# CC = g++
# SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
# OBJ_NAME = play
# INCLUDE_PATHS = -I/usr/local/include/SDL2 -Iinclude # <--------------      Change this to actual SDL2 path
# LIBRARY_PATHS = -L/usr/local/lib -Llib              # <--------------      Change this to actual lib path
# COMPILER_FLAGS = -std=c++11 -Wall -O0 -g
# LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer

# all:
# 	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME) $(LINKER_FLAGS)




# ------------------ Remove this the following comment to run and build on Mac ------------------ 

# SRC_DIR = src
# BUILD_DIR = build/release
# CC = g++
# SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
# OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))
# INCLUDE_PATHS = -Iinclude -I/usr/local/include/SDL2
# LIBRARY_PATHS = -Llib -L/usr/local/lib
# LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer
# COMPILER_FLAGS = -std=c++11 -Wall -O3
# OBJ_NAME = MTHELL
# EXECUTABLE = $(BUILD_DIR)/$(OBJ_NAME)
# ASSETS_DIR = res
# ASSETS_DEST = $(BUILD_DIR)/assets

# all: directories $(EXECUTABLE) copy_assets

# directories:
# 	mkdir -p $(BUILD_DIR)
# 	mkdir -p $(ASSETS_DEST)

# $(EXECUTABLE): $(OBJ_FILES)
# 	$(CC) $(OBJ_FILES) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $@

# $(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
# 	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) -c $< -o $@

# copy_assets:
# 	cp -r $(ASSETS_DIR)/* $(ASSETS_DEST)/

# clean:
# 	rm -rf $(BUILD_DIR)/*
# 	rm -rf $(ASSETS_DEST)/*

# .PHONY: all clean copy_assets directories




# ------------------ Remove this the following comment to run and build on Windows ------------------ 

# SRC_DIR = src
# BUILD_DIR = build\release
# CC = g++
# SRC_FILES = $(wildcard $(SRC_DIR)\*.cpp)
# OBJ_FILES = $(patsubst $(SRC_DIR)\%.cpp,$(BUILD_DIR)\%.o,$(SRC_FILES))
# INCLUDE_PATHS = -Iinclude -I/usr/local/include/SDL2  # <--------------      Change this to actual SDL2 path
# LIBRARY_PATHS = -Llib -L/usr/local/lib               # <--------------      Change this to actual lib path
# LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer
# COMPILER_FLAGS = -std=c++11 -Wall -O3
# OBJ_NAME = MTHELL
# EXECUTABLE = $(BUILD_DIR)\$(OBJ_NAME).exe
# ASSETS_DIR = res
# ASSETS_DEST = $(BUILD_DIR)\assets

# all: directories $(EXECUTABLE) copy_assets

# directories:
# 	if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
# 	if not exist "$(ASSETS_DEST)" mkdir "$(ASSETS_DEST)"

# $(EXECUTABLE): $(OBJ_FILES)
# 	$(CC) $(OBJ_FILES) $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $@

# $(BUILD_DIR)\%.o: $(SRC_DIR)\%.cpp
# 	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) -c $< -o $@

# copy_assets:
# 	xcopy /E /I /Y "$(ASSETS_DIR)" "$(ASSETS_DEST)\"

# clean:
# 	del /Q /F $(BUILD_DIR)\*
# 	del /Q /F $(ASSETS_DEST)\*
# 	rmdir /Q /S "$(BUILD_DIR)"
# 	rmdir /Q /S "$(ASSETS_DEST)"

# .PHONY: all clean copy_assets directories
