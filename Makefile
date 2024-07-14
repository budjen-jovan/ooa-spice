# Compiler
CXX := g++
# Compiler flags
CXXFLAGS := -std=c++17 -Wall -Werror -pedantic -O3 -I./include

# Directories
SRCDIR := src
OBJDIR := obj
INCDIR := include

# Source files
SOURCES := $(wildcard $(SRCDIR)/**/*.cpp $(SRCDIR)/*.cpp)
# Object files
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

# Targets
TARGET := ooa

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(TARGET)

