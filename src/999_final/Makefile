CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -fsanitize=address,undefined
LDLIBS = -lncurses
TARGET = sokoban
SRCS = main.cpp 
HEADERS = 
.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDLIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
