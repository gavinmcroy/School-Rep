package cpsc2150.MyQueue;

public class ArrayQueue<T> extends AbsQueue<T> implements IQueue<T> {

    /**
     * where the data is stored. myQ[0] is the front of the queue
     */
    private T[] myQ;
//


    /**
     * tracks how many items in the queue
     * also used to find the end of the queue
     *
     * @invariant 0 <= myLength < MAX_LENGTH
     * @correspondence total_element = myLength
     */
    private int myLength;

    /**
     * Initializes integer array of size MAX_LENGTH and initializes every
     * element in the array to 0
     *
     * @pre none
     * @post myQ == 0
     */
    ArrayQueue() {
        //Object[] ;
        myQ = (T[]) new Object[MAX_LENGTH];
        for (int i = 0; i < MAX_LENGTH; i++) {
            myQ[i] = null;
        }
        myLength = 0;
//        @SuppressWarnings("unchecked")
//        final T[] a = (T[]) Array.newInstance(c, MAX_LENGTH);
//        this.a = a;

    }

    /**
     * Queues a integer into the array by adding it to the back of the array
     *
     * @param x the integer to enqueue into the array
     */
    @Override
    public void enqueue(T x) {
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (myQ[i] != null && i != 0) {
                T val = myQ[i];
                myQ[i - 1] = val;
            }
        }
        myQ[MAX_LENGTH - 1] = x;
        myLength++;
    }

    /**
     * removes and returns the Integer at the front of the queue
     *
     * @return the variable at the front of the queue, 0 if a variable is not found
     */
    @Override
    public T dequeue() {
        int firstInteger = 0;
        for (int i = 0; i < MAX_LENGTH; i++) {
            if (myQ[i] != null) {
                firstInteger = i;
                break;
            }
        }
        if (myQ[firstInteger] != null) {
            T tmp = myQ[firstInteger];
            myQ[firstInteger] = null;
            myLength--;
            return tmp;
        }
        return null;
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
            myQ[i] = null;
        }
        myLength = 0;
    }
}
