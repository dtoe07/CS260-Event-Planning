pp	: main.o graph.o helper.o
	g++ -o app main.o graph.o helper.o

main.o	: main.cpp
	g++ -c main.cpp

graph.o	: graph.cpp
	g++ -c graph.cpp

helper.o	: helper.cpp
	g++ -c helper.cpp

clean	:
	rm *.o app
