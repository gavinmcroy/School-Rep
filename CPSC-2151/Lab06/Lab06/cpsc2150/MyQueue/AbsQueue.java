package cpsc2150.MyQueue;

public abstract class AbsQueue implements IQueue<T> {

    /**
     * Takes all the current members in the queue and nicely formats them with a string in the
     * same order they are held inside the queue
     *
     * @return returns a formatted string of all the elements inside the queue
     * @pre none
     * @post toString =  { all integers in the queue  }
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
