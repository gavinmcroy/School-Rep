package cpsc2150.MyQueue;

import java.util.ArrayList;
import java.util.List;

public class ListQueue implements IQueue {


    /**
     * this time store the queue in a list
     * myQ.get(0) is the front of the queue
     */
    private List<Integer> myQ;

    /* TODO Implement */
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
        int firstInteger = 0;
        for (int i = 0; i < myQ.size(); i++) {
            if (myQ.get(i) != 0) {
                firstInteger = i;
                break;
            }
        }

        int tmp = myQ.get(firstInteger);
        myQ.remove(firstInteger);
        return tmp;
    }

    /**
     * Gets the current length of the queue
     *
     * @return the current length of the queue
     */
    @Override
    public int length() {
        return myQ.size();
    }

    /**
     * Clears the queue by setting every element back equal to 0.
     * If the queue is empty it does nothing
     */
    @Override
    public void clear() {
        myQ.clear();
    }
}
