FLAGS= -Wall -Wextra -Werror -pedantic

tests: tests.c  masking.o
	cc $(FLAGS) -o tests tests.c masking.o

masking.o:
	cc $(FLAGS) -c masking.c

clean:
	rm masking.o tests
