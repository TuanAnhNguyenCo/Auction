main:
	g++ -o server server.cpp -Wall -Wextra -O2 -std=c++17

	
clean:
	rm -f *.0 server

s:
	./server