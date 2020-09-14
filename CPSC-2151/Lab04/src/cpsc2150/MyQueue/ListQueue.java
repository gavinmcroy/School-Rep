package cpsc2150.MyQueue;

import java.util.ArrayList;
import java.util.List;

public class ListQueue implements IQueue {


    /**
     * this time store the queue in a list
     * myQ.get(0) is the front of the queue
     */
    private List<Integer> myQ;

    /* TODO IMPLEMENT */
    ListQueue() {
        myQ = new ArrayList<>();
    }


    @Override
    /* TODO IMPLEMENT */
    public void enqueue(Integer x) {

    }

    @Override
    /* TODO IMPLEMENT */
    public Integer dequeue() {
        int tmp = myQ.get(0);
        myQ.remove(0);
        return tmp;
    }

    @Override
    public int length() {
        return myQ.size();
    }

    @Override
    public void clear() {
        myQ.clear();
    }
}
