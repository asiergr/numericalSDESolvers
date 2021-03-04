  IDIR =../include

  # the compiler: gcc for C program, define as g++ for C++
  CC = gcc

  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
  #  -I     - looks at current directory
  CFLAGS  = -I -g -Wall $(IDIR)
 
  # The build target 
  TARGET = main
 
  all: $(TARGET)
 
  $(TARGET): $(TARGET).c
              $(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
 
  clean:
              $(RM) $(TARGET)