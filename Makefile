# compiler and flags
CC = g++
CFLAGS = -Wall -std=c++11

# Directories
SRCDIR = src
INCDIR = include
BINDIR = ../bin

#source file
SRCS = $(wildcard $(SRCDIR)/*.cpp)
# OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(SRCS))
OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)

# Main target
TARGET = main

# Libraries
LIBS = -lGL -lGLU -lglut

# Rules
all: $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)


$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

clean:
	rm -rf $(BINDIR)

