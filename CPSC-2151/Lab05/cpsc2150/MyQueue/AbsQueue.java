package cpsc2150.MyQueue;

public abstract class AbsQueue implements IQueue {

    /*
     * TODO FINISH IMPLEMENTATION
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
