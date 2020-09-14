package cpsc2150.MyQueue;

public class ArrayQueue implements IQueue {

    // where the data is stored. myQ[0] is the front of the queue
    private Integer[] myQ;

    /**
     * tracks how many items in the queue
     * also used to find the end of the queue
     * Invariant  0<=myLength < MAX_LENGTH -> (100)
     */
    private int myLength = 0;

    /* TODO Implement Constructor */

    ArrayQueue() {
        myQ = new Integer[100];
    }


    @Override
    /* TODO IMPLEMENT */
    public void enqueue(Integer x) {
        myLength++;
    }

    @Override
    /* TODO IMPLEMENT */
    public Integer dequeue() {
        int tmp = myQ[0];
        myQ[0] = 0;
        return tmp;
    }

    @Override
    /* TODO IMPLEMENT */
    public int length() {
        return myLength;
    }

    @Override
    /* TODO IMPLEMENT */
    public void clear() {
        if (myLength == 0) {
            return;
        }
        for (int i = 0; i < MAX_LENGTH; i++) {
            myQ[i] = 0;
        }
    }
}
