
DEBUG = -g

CC = gcc
CFLAGS = -Wall $(DEBUG) -I.

SRC = parsing_numbers.c \
			convert_number.c \
			hash.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

parsing_numbers: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o parsing_numbers
