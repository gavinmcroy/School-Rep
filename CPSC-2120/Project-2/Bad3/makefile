break: 
	g++ -o prog1 prog1.cpp
	g++ -o bad1 bad1.cpp
	time ./bad1 100000 > input1
	time ./prog1 < input1
break2:
	g++ -o prog2 prog2.cpp
	g++ -o bad2 bad2.cpp
	time ./bad2 100000 > input2
	time ./prog2 < input2
break3:
	g++ -std=c++11 -o prog3 prog3.cpp
	g++ -std=c++11 -c  BinarySearchT.cpp
	g++ -std=c++11 -c  bad3.cpp
	g++ bad3.o BinarySearchT.o -o badProg
	time ./badProg 100000 > input3
	time ./prog3 < input3