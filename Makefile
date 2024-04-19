# Compiler and flags
CC = g++
CFLAGS = -Wall -std=c++11

# Directories
SRCDIR = src
INCDIR = include
BINDIR = bin
GAMEDIR = $(BINDIR)/game  # Define the game directory

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
SRCS += $(wildcard $(SRCDIR)/game/*.cpp)  # Add game-specific source files
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

# Main target
TARGET = main

# Libraries
LIBS = -lGL -lGLU -lglut

# Rules
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Create the directories before compiling
$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)  # Create the directory if it doesn't exist
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

clean:
	rm -rf $(BINDIR)

