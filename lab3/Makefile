# A Makefile with macros

FLAGS = -ansi -Wall
SOURCES = FileReverse.c
OBJECTS = FileReverse.o
EXEBIN = FileReverse

all: $(EXEBIN)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(FLAGS) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(OBJECTS)

clean :
	rm -f $(EXEBIN) $(OBJECTS))
