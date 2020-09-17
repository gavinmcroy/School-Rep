package cpsc2150.MyQueue;

/**
 * A queue containing integers.
 * A queue is a data structure where the first item added to the
 * structure is the first item removed from the structure
 * This queue is bounded by MAX_LENGTH
 */


public interface IQueue {

    public static final int MAX_LENGTH = 100;

    /**
     * Queues a integer into the array by adding it to the back of the array
     *
     * @param x the integer to enqueue into the array
     */
    void enqueue(Integer x);

    /**
     * removes and returns the Integer at the front of the queue
     * @return the variable at the front of the queue
     */
    Integer dequeue();

    /**
     * Gets the current length of the queue
     * @return the current length of the queue
     */
    int length();

    /* clears the entire queue */
    void clear();
}
