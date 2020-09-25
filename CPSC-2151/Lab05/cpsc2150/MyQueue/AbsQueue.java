package cpsc2150.MyQueue;

public abstract class AbsQueue implements IQueue {

    /**
     * Takes all the current members in the queue and nicely formats them with a string
     *
     * @return returns a formatted string of all the elements inside the queue
     * @pre none
     * @post toString = formattedQueue
     */
    @Override
    public String toString() {
        String formattedQueue = "";
        for (int i = 0; i < length(); i++) {
            Integer tmp = dequeue();
            if (i > 0) {
                formattedQueue = formattedQueue.concat(", " + tmp);
            } else {
                formattedQueue = formattedQueue.concat(tmp + "");
            }
            enqueue(tmp);
        }
        return formattedQueue;
    }

}
