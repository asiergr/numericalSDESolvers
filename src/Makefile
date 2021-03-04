  IDIR = ../include
  ODIR= ./obj

  # the compiler: gcc for C program, define as g++ for C++
  CC = gcc

  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
  #  -I     - looks at current directory
  CFLAGS  = -I -g -Wall $(IDIR)
 
  # Write down all the include files/dependencies
  _DEPS = hellomake.h
  # Grabs the location/name of all the header files
  DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

  # All the object files we will be creating
  _OBJ = hellomake.o hellofunc.o 
  # Gets all locations of object files adn puts it in a macro
  OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

  $(ODIR)/%.o: %.c $(DEPS)
	          $(CC) -c -o $@ $< $(CFLAGS)

  # The build target 
  TARGET = main
 
  all: $(TARGET)
 
  $(TARGET): $(TARGET).c
              $(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
 
  clean:
              $(RM) $(TARGET)