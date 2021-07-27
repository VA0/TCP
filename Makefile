all: compile link
compile:
	 g++ -std=c++17 -I include -c server.cpp
	 g++ -std=c++17 -I include -c client.cpp
link:
	g++ server.o -o server -L lib -l sfml-network
	g++ client.o -o client -L lib -l sfml-network -l sfml-system