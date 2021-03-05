IDIR = ../include
ODIR= ./obj

# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# Write down all the include files/dependencies
_DEPS = SDEs.h NumericalMethods.h
# Grabs the location/name of all the header files
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# All the object files we will be creating
_OBJ = SDEs.o NumericalMethods.o main.o
# Gets all locations of object files adn puts it in a macro
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Rule: All .o files depend on their .c versions. Make needs to compile
# the .c file using the CC compiler
# -c says to generate the object file
# -o $@ says to put it in the name to the left of :
# $< is the first item in the dependencies list

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Different builds
# Build all the object files
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Don't do anything with a file named clean
.PHONY: clean

#Cleans all object files
clean:
	rm -f $(ODIR)/*.o