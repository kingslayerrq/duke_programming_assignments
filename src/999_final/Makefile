CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined
TARGET = sokoban
SRCS = main.cpp 
HEADERS = 
.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
