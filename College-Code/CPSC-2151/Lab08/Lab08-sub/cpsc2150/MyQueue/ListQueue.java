package cpsc2150.MyQueue;

import java.util.*;

/**
 * @Invariants: 0 <= myQ.size() <= MAX_LENGTH
 * Correspondence: length = myQ.size();
 *                  self = queue as a list with myQ.get(0) as front of queue
 */

public class ListQueue<T> extends AbsQueue<T> {


    private List<T> myQ;

    /**
     * The constructor creates an "empty" queue
     * @post Queue is created and stored in a list
     */
    public ListQueue(){
        myQ = new ArrayList<T>();
    }


    /**
     * This method adds x to the end of the myQ
     */
    public void enqueue(T x) {

        myQ.add(x);

    }


    /**
     * This method removes and returns the Integer at the front of myQ
     */
    public T dequeue() {
        T frontInt = myQ.get(0);
        myQ.remove(0); //remove Integer at index 0
        return frontInt;
    }


    /**
     * This method returns |myQ|, the number of Integers in the myQ
     */
    public int length() {
        return myQ.size();
    }


    /**
     * This method clears all of myQ
     */
    public void clear() {
        myQ.clear();
    }
}
