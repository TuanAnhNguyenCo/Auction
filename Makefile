main:
	g++ -o server server.cpp -Wall -Wextra -O2 -std=c++17
	g++ -o client clientTest.cpp -Wall -Wextra -O2 -std=c++17


clean:
	rm -f *.0 server client

s:
	./server 5500
s2:
	./server 5501
s3:
	./server 5502
c:
	./client 5500
c2:
	./client 5501
c3:
	./client 5502
