# CXX = g++
# CXXFLAGS = -Wall -Wextra -Iinclude
# TARGET = lcl
# SRCDIR = sr
# INCDIR = include
# SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(SRCDIR)/%.o)

# all: $(TARGET)

# $(SRCDIR)/%.o: $(SRCDIR)/%.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# $(TARGET): $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# clean:
# 	rm -f $(SRCDIR)/*.o $(TARGET)

# run: $(TARGET)
# 	./$(TARGET)

# .PHONY: all clean run


CC = g++
CFLAGS = -Iinclude -Wall -Wextra -std=c++26 -O2
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = lcl

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
