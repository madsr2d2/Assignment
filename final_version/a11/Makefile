#Generic CPP makefile

# define the Cpp compiler to use
CXX = g++

# define any compile-time flags
CXXFLAGS	:= -std=c++17 -Wall -Wextra -g

# define library flags
LFLAGS =

# define output directory
OUTPUT	:= output

# define source directory
SRC		:= src

# define include directory
INCLUDE	:= include

# Define output file name
MAIN	:= main

# Find source dirs in current directory
SOURCEDIRS	:= $(shell find $(SRC) -type d)

# Find include dirs in current directory
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)

# Define remove command
RM = rm -f

# Needed for the clean target
FIXPATH = $1

# Make the output dir
MD	:= mkdir -p

# Generate include files
INCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

# Define the C source files
SOURCES		:= $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))

# Define the C source files
OBJECTS		:= $(SOURCES:.cpp=.o)

# Define main output file 
OUTPUTMAIN	:= $(call FIXPATH,$(OUTPUT)/$(MAIN))

# Make all
all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

# Make the output dir
$(OUTPUT):
	$(MD) $(OUTPUT)

# Make main from object files 
$(MAIN): $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS) $(LIBS)


# Rule for making object files from source files.
%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Declare "clean" as phony target
.PHONY: clean

# Clean 
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	@echo Cleanup complete!

# Run main
run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!