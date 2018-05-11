all: UnsortedListTest

UnsortedListTest: UnsortedListTest.o
	g++ -o UnsortedListTest UnsortedListTest.o

UnsortedListTest.o: UnsortedListTest.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors UnsortedListTest.cpp

UnsortedList.o: UnsortedList.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors UnsortedList.cpp

Student.o: Student.cpp
	g++ -c -Wall -std=c++14 -g -O0 -pedantic-errors Student.cpp

clean:
	rm -f UnsortedListTest
	rm -f UnsortedListTest.o
	rm -f UnsortedList.o
	rm -f Student.o