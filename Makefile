# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -I./SDL2/include -I./include -I./tracer/include -Ofast  # Updated include path

# Linker flags
LDFLAGS = -L./SDL2/lib -lmingw32 -lSDL2main -lSDL2
# -mwindows


# Target executable name
TARGET = ray_tracing

# Source files
SOURCES = main.cpp $(wildcard src/*.cpp) $(wildcard tracer/src/*.cpp) $(wildcard tracer/src/objects/*.cpp) $(wildcard tracer/src/lights/*.cpp)

# Object files (automatically generated from SOURCES)
OBJECTS = $(SOURCES:.cpp=.o)

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Rule for source files
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target
clean:
	del $(OBJECTS) $(TARGET).exe
