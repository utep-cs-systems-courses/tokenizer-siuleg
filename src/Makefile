# compiler flgas -g for debug, -O3 for optimization
CFLAGS=-g -O3

OBJS= ui.o string_actions.o 

# include file dependencies
history.o: history.h
tokenizer.o: tokenizer.h

all: tokenize

tokenize: $(OBJS)
	cc -o tokenize $(CFLAGS) $(OBJS)

clean:
	rm -f *.o tokenize

run:tokenize
	./tokenize

