curr=$(shell pwd)/
main.out:
	g++ main.cpp -std=c++17 -o main.out
	./main.out $(curr)

clean:
	rm -fv *.o *.out
