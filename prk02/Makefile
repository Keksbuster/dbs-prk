#
# GNU makefile fuer DBS Aufgabe 2a
#=================================


# compiler options
#--------------------------------
CC = gcc
CFLAGS = -Wall -g -I`pg_config --includedir`
LDFLAGS = -L`pg_config --libdir`

# project files
#--------------------------------
PROGRAM = dbimp
OBJECTS = main.o db.o


# rules
#----------------------------------
all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CC) -o $@ $+ $(LDFLAGS) -lpq 

# generic rule for compiling *.c -> *.o
%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $*.c

clean:
	rm -f $(PROGRAM) $(OBJECTS)

