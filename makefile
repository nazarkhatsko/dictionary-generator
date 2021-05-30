# name project
TAG := dg

# name compiler
CC := g++

# source
SRC := main.cpp
SRC += $(wildcard source/*.cpp)

# include
INC := -Iinclude/

# compiler flags
FLAG := -Wall
FLAG += -std=c++17

# mode list
.PHONY: release debug clean

# release mode
release: build/release/$(TAG)

build/release/$(TAG): $(SRC)
	@echo "[RELEASE]"
	@mkdir -p build/release/
	@$(CC) $(FLAG) $(INC) -O3 $^ -o $@

# debug mode
debug: build/debug/$(TAG)

build/debug/$(TAG): $(SRC)
	@echo "[DEBUG]"
	@mkdir -p build/debug/
	@$(CC) $(FLAG) $(INC) -g $^ -o $@

# clean mode
clean:
	@echo "[CLEAN]"
	@rm -r -f build/
