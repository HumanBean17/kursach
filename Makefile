SRC = main.cpp additional_func.cpp

all:
	g++ $(SRC)

clean:
	rm -f a.out

re:	clean all