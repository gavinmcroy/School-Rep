package cpsc2150.MyQueue;

/**
 * A queue containing integers.
 * A queue is a data structure where the first item added to the
 * structure is the first item removed from the structure
 * This queue is bounded by MAX_LENGTH
 */


public interface IQueue {

    public static final int MAX_LENGTH = 100;

    /* Adds x to the end of the queue */
    void enqueue(Integer x);

    /* removes and returns the Integer at the front of the queue */
    Integer dequeue();

    /* returns the number of Integers in the Queue */
    int length();

    /* clears the entire queue */
    void clear();
}
