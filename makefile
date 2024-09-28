# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = library_app

# Source files (with paths)
SRCS = main.cpp student.cpp librarian.cpp books.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target: build the program
all: $(TARGET)

# Compile the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o object files, placing object files in the CPP directory
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)