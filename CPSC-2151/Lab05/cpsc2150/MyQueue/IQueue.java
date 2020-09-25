package cpsc2150.MyQueue;

/**
 * A queue containing integers.
 * A queue is a data structure where the first item added to the
 * structure is the first item removed from the structure
 * This queue is bounded by MAX_LENGTH
 * <p>
 * Initialization Ensures:
 * Ensures data elements are initialized to 0
 * <p>
 * Defines:
 * total_elements : Z
 * <p>
 * Constraint:
 * 0 <= total_elements < MAX_SIZE
 */


public interface IQueue {

    public static final int MAX_LENGTH = 100;

    /**
     * Queues a integer into the array by adding it to the back of the array
     *
     * @param x the integer to enqueue into the array
     * @pre None
     * @post total_element = #total_element + 1
     */
    void enqueue(Integer x);

    /**
     * removes and returns the Integer at the front of the queue
     *
     * @return the variable at the front of the queue
     * @pre None
     * @post total_elements = #total_elements - 1
     */
    Integer dequeue();

    /**
     * Gets the current length of the queue
     *
     * @return the current length of the queue
     * @pre None
     * @post length = total_elements
     */
    int length();

    /**
     * Clears the queue by setting every element back equal to 0.
     * If the queue is empty it does nothing
     *
     * @pre None
     * @post total_elements = 0
     */
    void clear();


    /**
     * Prints the current elements inside the queue
     * Only for debug purposes
     *
     * @pre None
     * @post None
     */
    void printList();

    /**
     * returns the integer at the front of the queue but does not
     * remove it from the queue (final state of the queue is equivalent to the initial state of the
     * queue, the queue can change during the method)
     *
     * @return the integer at the front of the queue but does not
     * remove it from the queue
     * @pre
     * @post
     */
    default Integer peek() {
        return null;
    }

    /**
     * returns the integer at the end of the queue, but does
     * not remove it from the queue
     *
     * @return
     * @pre
     * @post
     */
    default Integer endOfQueue() {
        return null;
    }

    /**
     * inserts x at position pos in the queue.
     * Pos index starts at 1, so the item at the very front of the queue is pos 1
     *
     * @param x
     * @param pos
     * @pre
     * @post
     */
    default void insert(Integer x, int pos) {

    }

    /**
     * removes whatever integer was in position pos in
     * the queue and returns it. Pos index starts at 1, so the item at the very front of the
     * queue is pos 1
     *
     * @param pos
     * @return
     * @pre
     * @post
     */
    default Integer remove(int pos) {
        return null;
    }

    /**
     * returns whatever integer was in position pos in the
     * queue and without removing it. Pos index starts at 1, so the item at the very front of
     * the queue is pos 1
     *
     * @param pos
     * @return
     * @pre
     * @post
     */
    default Integer get(int pos) {
        return null;
    }


}
