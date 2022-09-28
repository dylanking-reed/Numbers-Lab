FLAGS= -Wall -Wextra -Werror -pedantic
OBJS=masking.o negation.o overflow.o
BINS=tests

tests: tests.c  $(OBJS)
	cc $(FLAGS) -o tests tests.c $(OBJS)

masking.o:
	cc $(FLAGS) -c masking.c

negation.o:
	cc $(FLAGS) -c negation.c
	
overflow.o:
	cc $(FLAGS) -c overflow.c

clean:
	rm $(OBJS) $(BINS)
