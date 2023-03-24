default: 
	javac cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/DoubleQueueApp.java
	
runInt:
	java cpsc2150.MyQueue.QueueApp 
runDouble:
	java cpsc2150.MyQueue.DoubleQueueApp
test:
	javac -cp .:/usr/share/java/junit4.jar cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/DoubleQueueApp.java cpsc2150/MyQueue/TestArrayQueue.java cpsc2150/MyQueue/TestListQueue.java
java  -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.MyQueue.TestArrayQueue
java  -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.MyQueue.TestListQueue

testArr:
	javac -cp .:/usr/share/java/junit4.jar cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/DoubleQueueApp.java cpsc2150/MyQueue/TestArrayQueue.java cpsc2150/MyQueue/TestListQueue.java
java  -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.MyQueue.TestArrayQueue

testList:
	javac -cp .:/usr/share/java/junit4.jar cpsc2150/MyQueue/IQueue.java cpsc2150/MyQueue/ListQueue.java cpsc2150/MyQueue/ArrayQueue.java cpsc2150/MyQueue/AbsQueue.java cpsc2150/MyQueue/QueueApp.java cpsc2150/MyQueue/DoubleQueueApp.java cpsc2150/MyQueue/TestArrayQueue.java cpsc2150/MyQueue/TestListQueue.java
java  -cp .:/usr/share/java/junit4.jar org.junit.runner.JUnitCore cpsc2150.MyQueue.TestListQueue

clean:
	$(RM) cpsc2150/MyQueue/*.class
