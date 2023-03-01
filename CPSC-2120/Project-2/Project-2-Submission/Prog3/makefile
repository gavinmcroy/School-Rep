break:
	g++ -std=c++11 -o prog3 prog3.cpp
	g++ -std=c++11 -c  BinarySearchT.cpp
	g++ -std=c++11 -c  bad3.cpp
	g++ bad3.o BinarySearchT.o -o badProg
	time ./badProg 100000 > input3
	time ./prog3 < input3