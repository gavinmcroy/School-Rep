package cpsc2150.MyQueue;

import java.util.ArrayList;
import java.util.List;

public class ListQueue extends AbsQueue implements IQueue {


    /**
     * this time store the queue in a list
     * myQ.get(0) is the front of the queue
     *
     * @correspondence total_elements = myQ.size() ?
     */
    private List<Integer> myQ;

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
    public void enqueue(Integer x) {
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
    public Integer dequeue() {
        boolean foundVal = false;
        int firstInteger = 0;
        for (int i = 0; i < myQ.size(); i++) {
            if (myQ.get(i) != 0) {
                firstInteger = i;
                foundVal = true;
                break;
            }
        }
        if (foundVal) {
            int tmp = myQ.get(firstInteger);
            myQ.remove(firstInteger);
            return tmp;
        }
        return 0;
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
