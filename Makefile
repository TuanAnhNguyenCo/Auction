main:
	g++ -o server server.cpp -Wall -Wextra -O2 -std=c++17
	g++ -o client clientTest.cpp -Wall -Wextra -O2 -std=c++17


clean:
	rm -f *.0 server client

s:
	./server 5500
c:
	./client
