CXX      = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -Iinclude

SRC      := $(wildcard src/*.cpp)
OBJ      := $(patsubst src/%.cpp,bin/%.o,$(SRC))
TARGET   := bin/library_app

all: $(TARGET)

bin/%.o: src/%.cpp | bin
 $(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
 $(CXX) $(CXXFLAGS) $^ -o $@

bin:
 mkdir -p bin

clean:
 rm -rf bin
