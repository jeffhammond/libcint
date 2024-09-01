CC = gcc-14
OPENMP = -fopenmp

CPPFLAGS = -I../include
LDFLAGS = $(OPENMP) -L..
LIBS = -lcint

CFLAGS = $(CPPFLAGS) $(OPENMP) -g -O3

all: time_c2h6.x time_c60.x

%.x: %.o
	$(CC) $(LDFLAGS) $< $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f *.o *.x
	-rm -rf *.dSYM

