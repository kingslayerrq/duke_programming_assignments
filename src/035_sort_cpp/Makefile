# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
TARGET = sortLines
SRC = sortLines.cpp

# Default rule (runs when you just type 'make')
all: $(TARGET)

# Rule to compile the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Rule to clean up build files
clean:
	rm -f $(TARGET) *.o
