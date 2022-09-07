package cpsc2150.MyQueue;

import org.junit.Test;

import static org.junit.Assert.assertTrue;

public class TestListQueue {
    private IQueue<Double> MakeAQueue() {
        IQueue newQueue = new ListQueue();
        return newQueue;
    }

    //insert when queue is empty
    @Test
    public void testEnqueue_emptyQueue() {
        Double value = 1.0;
        IQueue myQueue = MakeAQueue();

        myQueue.enqueue(value);

        assertTrue(myQueue.get(1) == value && myQueue.length() == 1);
    }

    //insert when one away from MAX_LENGTH
    @Test
    public void testEnqueue_almostFullQueue() {
        Double value = 2.5;
        IQueue myQueue = MakeAQueue();
        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < (myQueue.MAX_LENGTH) - 1; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }

        myQueue.enqueue(value);
        queueString.append(", " + value);
        String tempString = queueString.toString();

        assertTrue(myQueue.get(IQueue.MAX_LENGTH) == value &&
                myQueue.length() == IQueue.MAX_LENGTH &&
                myQueue.toString().equals(tempString));
    }

    //standard enqueue
    @Test
    public void testEnqueue_20ElementQueue() {
        Double value = 3.6;
        IQueue myQueue = MakeAQueue();
        StringBuilder queueString = new StringBuilder();
        int numElements = 20;

        for (double i = 0; i < numElements; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }

        myQueue.enqueue(value);
        queueString.append(", " + value);
        String tempString = queueString.toString();

        assertTrue(myQueue.get(numElements + 1) == value &&
                myQueue.length() == numElements + 1 &&
                myQueue.toString().equals(tempString));
    }

    @Test
    public void testDequeue_oneElementQueue() {
        Double value = 1.0;
        IQueue myQueue = MakeAQueue();

        myQueue.enqueue(value);

        Double removed = (Double) myQueue.dequeue();
        assertTrue(myQueue.length() == 0 && removed.equals(value)
                && myQueue.toString().equals(""));
    }

    ///full
    @Test
    public void testDequeue_fullQueue() {
        Double value = 3.6;
        IQueue myQueue = MakeAQueue();
        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < myQueue.MAX_LENGTH; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }

        Double removed = (Double) myQueue.dequeue();
        queueString.delete(0, 5);
        String tempString = queueString.toString();

        assertTrue(removed == 0 && myQueue.length() == IQueue.MAX_LENGTH - 1 &&
                myQueue.toString().equals(tempString));
    }

    //standard
    @Test
    public void testDequeue_20ElementQueue() {
        Double value = 3.6;
        IQueue myQueue = MakeAQueue();
        StringBuilder queueString = new StringBuilder();
        int numElements = 20;

        for (double i = 0; i < numElements; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }

        Double removed = (Double) myQueue.dequeue();
        queueString.delete(0, 5);
        String tempString = queueString.toString();

        assertTrue(removed == 0 && myQueue.length() == numElements - 1 &&
                myQueue.toString().equals(tempString));
    }

    @Test
    public void testClear_emptyQueue() {
        IQueue myQueue = MakeAQueue();

        myQueue.clear();

        assertTrue(myQueue.length() == 0 && myQueue.toString().equals(""));
    }

    @Test
    public void testClear_fullQueue() {
        IQueue myQueue = MakeAQueue();


        for (double i = 0; i < myQueue.MAX_LENGTH; i++) {
            myQueue.enqueue(i);
        }

        myQueue.clear();

        assertTrue(myQueue.length() == 0 && myQueue.toString().equals(""));
    }

    @Test
    public void testClear_20ElementQueue() {
        IQueue myQueue = MakeAQueue();
        int numElements = 20;


        for (double i = 0; i < numElements; i++) {
            myQueue.enqueue(i);
        }

        myQueue.clear();

        assertTrue(myQueue.length() == 0 && myQueue.toString().equals(""));
    }

    @Test
    public void testPeek_1elementQueue() {
        IQueue myQueue = MakeAQueue();
        Double value = 1.4;

        myQueue.enqueue(value);
        int myLength = myQueue.length();

        Double frontValue = (Double) myQueue.peek();

        assertTrue(myLength == myQueue.length() &&
                value == frontValue);

    }

    @Test
    public void testPeek_fullQueue() {
        IQueue myQueue = MakeAQueue();

        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < myQueue.MAX_LENGTH; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }
        int myLength = myQueue.length();
        String tempString = queueString.toString();


        Double frontValue = (Double) myQueue.peek();

        assertTrue(myLength == myQueue.length() &&
                frontValue == 0 &&
                myQueue.toString().equals(tempString));

    }

    @Test
    public void testPeek_20ElementQueue() {
        IQueue myQueue = MakeAQueue();
        int numElements = 20;

        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < numElements; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }
        int myLength = myQueue.length();
        String tempString = queueString.toString();

        Double frontValue = (Double) myQueue.peek();

        assertTrue(myLength == myQueue.length() &&
                frontValue == 0 &&
                myQueue.toString().equals(tempString));

    }

    @Test
    public void testEndOfQueue_1elementQueue(){
        IQueue myQueue = MakeAQueue();
        Double value = 7.4;

        myQueue.enqueue(value);
        int myLength = myQueue.length();

        Double endValue = (Double) myQueue.endOfQueue();

        assertTrue(myLength == myQueue.length() &&
                value == endValue);
    }

    @Test
    public void testEndOfQueue_fullQueue(){
        IQueue myQueue = MakeAQueue();
        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < myQueue.MAX_LENGTH; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }
        int myLength = myQueue.length();
        String tempString = queueString.toString();


        Double frontValue = (Double) myQueue.endOfQueue();

        assertTrue(myLength == myQueue.length() &&
                frontValue == myQueue.MAX_LENGTH-1 &&
                myQueue.toString().equals(tempString));
    }

    @Test
    public void testEndOfQueue_20ElementQueue(){
        IQueue myQueue = MakeAQueue();
        StringBuilder queueString = new StringBuilder();
        int numElements = 20;

        for (double i = 0; i < numElements; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }
        int myLength = myQueue.length();
        String tempString = queueString.toString();


        Double frontValue = (Double) myQueue.endOfQueue();

        assertTrue(myLength == myQueue.length() &&
                frontValue == numElements-1 &&
                myQueue.toString().equals(tempString));
    }

    @Test
    public void testInsert_emptyQueue(){
        IQueue myQueue = MakeAQueue();
        Double value = 3.4;
        int pos = 1;

        myQueue.insert(value, pos);

        assertTrue(myQueue.length() == 1
                && myQueue.toString().equals("3.4"));

    }

    @Test
    public void testInsert_almostFullQueue(){
        IQueue myQueue = MakeAQueue();
        Double value = 3.2;

        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < myQueue.MAX_LENGTH-1; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }

        int pos = 2;

        myQueue.insert(value, pos);
        int myLength = myQueue.length();
        String myString = ""+value;
        queueString.insert(5, myString + ", ");

        assertTrue(myQueue.length() == myLength
                && myQueue.toString().equals(queueString.toString()));

    }

    @Test
    public void testInsert_atEndOfQueue(){
        IQueue myQueue = MakeAQueue();
        Double value = 3.2;
        int numElements = 3;

        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < numElements; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }

        int pos = 4;

        myQueue.insert(value, pos);
        int myLength = myQueue.length();

        queueString.append(", " + value);

        assertTrue(myQueue.length() == myLength
                && myQueue.toString().equals(queueString.toString()));

    }

    @Test
    public void testRemove_Remove1Element(){
        IQueue myQueue = MakeAQueue();
        Double value = 3.4;

        myQueue.enqueue(value);

        Double removed = (Double) myQueue.remove(1);

        assertTrue(myQueue.length() == 0
                && removed == value);

    }

    @Test
    public void testRemove_AtEndOfFullQueue(){
        IQueue myQueue = MakeAQueue();

        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < myQueue.MAX_LENGTH; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }


        Double removed = (Double) myQueue.remove(myQueue.MAX_LENGTH);
        queueString.delete(580, 586);

        assertTrue(myQueue.length() == myQueue.MAX_LENGTH-1
                && myQueue.toString().equals(queueString.toString()));

    }

    @Test
    public void testRemove_inMiddleOfQueue(){
        IQueue myQueue = MakeAQueue();
        int numElements = 5;

        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < numElements; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }


        Double removed = (Double) myQueue.remove(2);
        queueString.delete(4,9);

        assertTrue(myQueue.length() == numElements-1
                && myQueue.toString().equals(queueString.toString()));

    }

    @Test
    public void testGet_1ElementQueue(){
        IQueue myQueue = MakeAQueue();
        Double value = 5.6;
        StringBuilder queueString = new StringBuilder();

        myQueue.enqueue(value);
        int myLength = myQueue.length();
        queueString.append(value);

        Double got = (Double) myQueue.get(1);

        assertTrue(myQueue.length() == myLength
                && got == value &&
                myQueue.toString().equals(queueString.toString()));
    }

    @Test
    public void testGet_fullQueue(){
        IQueue myQueue = MakeAQueue();
        StringBuilder queueString = new StringBuilder();

        for (double i = 0; i < myQueue.MAX_LENGTH; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }
        int myLength = myQueue.length();

        Double got = (Double) myQueue.get(myQueue.MAX_LENGTH);

        assertTrue(myQueue.length() == myLength
                && got == myQueue.MAX_LENGTH-1 &&
                myQueue.toString().equals(queueString.toString()));
    }

    @Test
    public void testGet_20ElementQueue(){
        IQueue myQueue = MakeAQueue();
        StringBuilder queueString = new StringBuilder();
        int numElements = 20;

        for (double i = 0; i < numElements; i++) {
            myQueue.enqueue(i);
            if (i == 0) queueString.append(i);
            else queueString.append(", " + i);
        }
        int myLength = myQueue.length();

        Double got = (Double) myQueue.get(2);

        assertTrue(myQueue.length() == myLength
                && got == 1.0 &&
                myQueue.toString().equals(queueString.toString()));
    }
}
