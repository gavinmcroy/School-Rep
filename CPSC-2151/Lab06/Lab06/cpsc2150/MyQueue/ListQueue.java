package cpsc2150.MyQueue;

import java.util.ArrayList;
import java.util.List;

public class ListQueue<T> extends AbsQueue<T> implements IQueue<T> {


    /**
     * this time store the queue in a list
     * myQ.get(0) is the front of the queue
     *
     * @correspondence total_elements = myQ.size() ?
     */
    private List<T> myQ;
/**@Contract (x<10) */
    /**
     * Initializes myQ to a new empty array list
     *
     * @pre none
     * @post myQ != null
     */
    ListQueue() {
        myQ = new ArrayList<>();
    }


    /**
     * Queues a integer into the array by adding it to the back of the array
     *
     * @param x the integer to enqueue into the array
     */
    @Override
    public void enqueue(T x) {
        int tmp = myQ.size();
        if (tmp == 0) {
            myQ.add(x);
        } else {
            myQ.add(tmp, x);
        }
    }

    /**
     * removes and returns the Integer at the front of the queue
     *
     * @return the variable at the front of the queue
     */
    @Override
    public T dequeue() {
        boolean foundVal = false;
        int firstInteger = 0;
        for (int i = 0; i < myQ.size(); i++) {
            if (myQ.get(i) !=null) {
                firstInteger = i;
                foundVal = true;
                break;
            }
        }
        if (foundVal) {
            T tmp = myQ.get(firstInteger);
            myQ.remove(firstInteger);
            return tmp;
        }

        return null;
    }

    /**
     * Gets the current length of the queue
     *
     * @return the current length of the queue
     * @pre none
     * @post none
     */
    @Override
    public int length() {
        return myQ.size();
    }

    /**
     * Clears the queue by setting every element back equal to 0.
     * If the queue is empty it does nothing. The list will be empty after this call
     *
     * @pre none
     * @post [all usable elements of myQ = 0]
     */
    @Override
    public void clear() {
        if (myQ.size() == 0) {
            return;
        }
        myQ.clear();
    }

}
