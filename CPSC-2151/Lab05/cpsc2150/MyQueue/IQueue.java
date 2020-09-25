package cpsc2150.MyQueue;

import java.util.ArrayList;

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
     * TODO POST CONDITION
     * returns the integer at the front of the queue but does not
     * remove it from the queue (final state of the queue is equivalent to the initial state of the
     * queue, the queue can change during the method)
     *
     * @return the integer at the front of the queue but does not
     * remove it from the queue
     * @pre length() > 0
     * @post peek =
     */
    default Integer peek() {
        Integer x = dequeue();
        enqueue(x);

        for (int i = 0; i < length() - 1; i++) {
            Integer tmp = dequeue();
            enqueue(tmp);
        }
        return x;
    }

    /**
     * TODO POST CONDITION
     * returns the integer at the end of the queue, but does
     * not remove it from the queue
     *
     * @return returns the integer at the end of the queue. Note it does NOT remove it from the queue
     * @pre |self| > 0 and length() > 0
     * @post endOfQueue = |self| > 0 and length() > 0
     */
    default Integer endOfQueue() {
        Integer x = null;
        for (int i = 0; i < length(); i++) {
            x = dequeue();
            enqueue(x);
        }
        return x;
    }

    /**
     * TODO IMPLEMENT POST CONDITION
     * inserts x at position pos in the queue.
     * Pos index starts at 1, so the item at the very front of the queue is pos 1
     *
     * @param x   the integer to be inserted into the queue
     * @param pos the position in the queue where the integer will be entered if pos = 1 then its accessing [0]
     * @pre x != null and pos > 0 and pos <= MAX_SIZE and length < 100
     * @post self = <x> pos #self [self = x added to position pos in #self] and length() >= 1
     */
    default void insert(Integer x, int pos) {
        ArrayList<Integer> tmp = new ArrayList<>();
        //---Length reduces on each dequeue so you have to store initial size
        int length = length();
        for (int i = 0; i < length; i++) {
            Integer add = dequeue();
            //---Pos = 1 at position [0]
            if (i == pos - 1) {
                tmp.add(x);
            }
            tmp.add(add);
        }
        clear();
        for (Integer integer : tmp) {
            enqueue(integer);
        }
    }

    /**
     * TODO FINISH POST CONDITION
     * removes whatever integer was in position pos in
     * the queue and returns it. Pos index starts at 1, so the item at the very front of the
     * queue is pos 1
     *
     * @param pos the position of an element inside of the queue
     * @return the integer that was removed from the queue
     * @pre pos > 0 and pos <= MAX_SIZE and |self| > 0 and length() > 0
     * @post remove() = and #self = remove(pos) o self [self = remove(pos) removed from the position pos in #self]
     */
    default Integer remove(int pos) {
        Integer removeInt = null;
        for (int i = 0; i < length(); i++) {
            if (i == pos - 1) {
                removeInt = dequeue();
            }
            Integer tmp = dequeue();
            enqueue(tmp);
        }
        return removeInt;
    }

    /**
     * TODO FINISH POST CONDITION
     * returns whatever integer was in position pos in the
     * queue and without removing it. Pos index starts at 1, so the item at the very front of
     * the queue is pos 1
     *
     * @param pos the position of the element you want to get from the queue
     * @return the value located at pos inside the queue
     * @pre pos > 0 and pos <= 100
     * @post get() =
     */
    default Integer get(int pos) {
        Integer getInt = null;
        for (int i = 0; i < length(); i++) {
            if (i == pos - 1) {
                getInt = dequeue();
                enqueue(getInt);
            } else {
                Integer tmp = dequeue();
                enqueue(tmp);
            }
        }
        return getInt;
    }


}
