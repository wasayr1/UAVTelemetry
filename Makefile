# Compiler
CC = g++

# Compiler flags
CFLAGS = -g -Wall

# Source files
SRCS = main.cpp Drone.cpp

# Executable name
TARGET = simulator

# Default build rule
all: $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)