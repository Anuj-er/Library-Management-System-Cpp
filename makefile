# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = library_app

# Source files
SRCS = main.cpp student.cpp librarian.cpp books.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target: build the program
all: $(TARGET)

# Compile the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)