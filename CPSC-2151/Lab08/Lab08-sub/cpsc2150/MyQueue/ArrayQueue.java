package cpsc2150.MyQueue;


/**
 * @invariant 0 <= myLength < MAX_LENGTH
 *
 * Correspondence: self = reversed array of Integers in the order that they are
 * added into the array, length = myLength
 */

public class ArrayQueue<T> extends AbsQueue<T> {

    // where the data is stored. myQ[0] is the front of the queue
    private T[] myQ;

    private int myLength;

    /**
     * The constructor creates an "empty" queue
     * @post Queue is created and stored in an array, myQ
     */
    public ArrayQueue()
    {
        myLength = 0;
        myQ = (T[]) new Object[MAX_LENGTH];
    }

    /**
     * This method adds x to the end of myQ
     */
    public void enqueue(T x) {
        myQ[myLength] = x;
        myLength++;
    }
    /**
     * This method removes and returns T at the front of the myQ
     */
    public T dequeue() {
        T temp = myQ[0];
        for(int i = 1; i < myLength; i++)
            myQ[i-1] = myQ[i];
        myLength--;
        return temp;
    }

    /**
     * This method returns the number of T's in myQ
     */
    public int length() {
        return myLength;
    }

    /**
     * This method clears the entire myQ
     */
    public void clear() {
        myQ = null;
        myLength = 0;
    }


}

