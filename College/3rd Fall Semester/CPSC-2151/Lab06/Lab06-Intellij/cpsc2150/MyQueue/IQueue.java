package cpsc2150.MyQueue;

import java.util.ArrayList;

/**
 * A queue containing integers.
 * A queue is a data structure where the first item added to the
 * structure is the first item removed from the structure
 * This queue is bounded by MAX_LENGTH
 * <p>
 * Initialization Ensures:
 * Ensures data elements are initialized to null
 * <p>
 * Defines:
 * total_elements : Z
 * <p>
 * Constraint:
 * 0 <= total_elements < MAX_SIZE
 */

public interface IQueue<T> {

    public static final int MAX_LENGTH = 100;

    /**
     * Queues a integer into the array by adding it to the back of the array
     *
     * @param o the integer to enqueue into the array
     * @pre total_elements <= MAX_LENGTH
     * @post total_element = #total_element + 1
     *       self = o added to the back of #self
     */
    void enqueue(T o);

    /**
     * removes and returns the Integer at the front of the queue
     *
     * @return the variable at the front of the queue
     * @pre total_elements > 0
     * @post total_elements = #total_elements - 1
     *       self = dequeue() remove from the front of #self
     */
    T dequeue();

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
     * returns the integer at the front of the queue but does not
     * remove it from the queue (final state of the queue is equivalent to the initial state of the
     * queue, the queue can change during the method)
     *
     * @return the integer at the front of the queue but does not
     * remove it from the queue
     * @pre length() > 0
     * @post peek = dequeue()
     */
    default T peek() {
        T x = dequeue();
        enqueue(x);

        for (int i = 0; i < length() - 1; i++) {
            T tmp = dequeue();
            enqueue(tmp);
        }
        return x;
    }

    /**
     * returns the integer at the end of the queue, but does
     * NOT remove it from the queue
     *
     * @return returns the integer at the end of the queue. Note it does NOT remove it from the queue
     * @pre |self| > 0 and length() > 0
     * @post endOfQueue = [Last element in queue] and |self| > 0 and length() > 0
     */
    default T endOfQueue() {
        T x = null;
        for (int i = 0; i < length(); i++) {
            x = dequeue();
            enqueue(x);
        }
        return x;
    }

    /**
     * inserts x at position pos in the queue.
     * Pos index starts at 1, so the item at the very front of the queue is pos 1. Therefore accessing element
     * [0] is done by entering 1 for the position
     *
     * @param x   the integer to be inserted into the queue
     * @param pos the position in the queue where the integer will be entered if pos = 1 then its accessing [0]
     * @pre x != null and pos > 0 and pos <= MAX_SIZE and length() < 100
     * @post self = <x> pos #self [self = x added to position pos in #self] and length() >= 1
     */
    default void insert(T x, int pos) {
        ArrayList<T> tmp = new ArrayList<>();
        //---Special case if length is 0
        if (length() == 0) {
            enqueue(x);
            return;
        }
        //---Length reduces on each dequeue so you have to store initial size
        int length = length();
        for (int i = 0; i < length; i++) {
            T add = dequeue();
            //---Pos = 1 at position [0]
            if (i == pos - 1) {
                tmp.add(x);
            }
            tmp.add(add);
        }
        clear();
        for (T o : tmp) {
            enqueue(o);
        }
    }

    /**
     * removes whatever integer was in position pos in
     * the queue and returns it. Pos index starts at 1, so the item at the very front of the
     * queue is pos 1
     *
     * @param pos the position of an element inside of the queue
     * @return the integer that was removed from the queue
     * @pre pos > 0 and pos <= MAX_SIZE and |self| > 0 and length() > 0
     * @post remove() = (#self = remove(pos) o self) [self = remove(pos) removed from the position pos in #self]
     */
    default T remove(int pos) {
        T removeInt = null;
        for (int i = 0; i < length(); i++) {
            if (i == pos - 1) {
                removeInt = dequeue();
            }
            T tmp = dequeue();
            enqueue(tmp);
        }
        return removeInt;
    }

    /**
     * returns whatever integer was in position pos in the
     * queue and WITHOUT removing it. Pos index starts at 1, so the item at the very front of
     * the queue is pos 1
     *
     * @param pos the position of the element you want to get from the queue
     * @return the value located at pos inside the queue
     * @pre pos > 0 and pos <= 100
     * @post get() = [self at get(pos)] [( get() = the element present in self at position pos)]
     */
    default T get(int pos) {
        T getInt = null;
        for (int i = 0; i < length(); i++) {
            if (i == pos - 1) {
                getInt = dequeue();
                enqueue(getInt);
            } else {
                T tmp = dequeue();
                enqueue(tmp);
            }
        }
        return getInt;
    }


}
