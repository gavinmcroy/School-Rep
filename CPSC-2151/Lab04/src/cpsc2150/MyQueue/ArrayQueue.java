package cpsc2150.MyQueue;

public class ArrayQueue implements IQueue {

    /**
     * where the data is stored. myQ[0] is the front of the queue
     */
    private Integer[] myQ;

    /**
     * tracks how many items in the queue
     * also used to find the end of the queue
     * @invariant  0 <= myLength < MAX_LENGTH
     */
    private int myLength = 0;

    /* TODO Implement */
    ArrayQueue() {
        myQ = new Integer[100];
        for (int i = 0; i < MAX_LENGTH; i++) {
            myQ[i] = 0;
        }
    }

    /**
     * Queues a integer into the array by adding it to the back of the array
     *
     * @param x the integer to enqueue into the array
     */
    @Override
    public void enqueue(Integer x) {
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (myQ[i] != 0 && i != 0) {
                int val = myQ[i];
                myQ[i - 1] = val;
            }
        }
        myQ[MAX_LENGTH - 1] = x;
        myLength++;
    }

    /**
     * removes and returns the Integer at the front of the queue
     *
     * @return the variable at the front of the queue
     */
    @Override
    public Integer dequeue() {
        int firstInteger = 0;
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (myQ[i] != 0) {
                firstInteger = i;
                break;
            }
        }
        if (myQ[firstInteger] != 0) {
            int tmp = myQ[firstInteger];
            myQ[firstInteger] = 0;
            return tmp;
        }
        return 0;
    }

    /**
     * Gets the current length of the queue
     *
     * @return the current length of the queue
     */
    @Override
    public int length() {
        return myLength;
    }

    /**
     * Clears the queue by setting every element back equal to 0.
     * If the queue is empty it does nothing
     */
    @Override
    public void clear() {
        if (myLength == 0) {
            return;
        }
        for (int i = 0; i < MAX_LENGTH; i++) {
            myQ[i] = 0;
        }
    }
}
