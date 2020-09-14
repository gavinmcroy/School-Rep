package cpsc2150.MyQueue;

public class QueueApp {

    public static void main(String[] args) {
        IQueue q = null;
        /*
        You will add in code here to ask the user whether they want an
        array implementation or a list implementation. Then use their
        answer to initialize q appropriately
        */
        Integer x = 42;
        q.enqueue(x);
        x = 17;
        q.enqueue(x);
        x = 37;
        q.enqueue(x);
        x = 36;
        q.enqueue(x);
        x = 12;
        q.enqueue(x);
        //Add the code to print the queue. After the code is finished,
        //the queue should still contain all its values in order
    }
}
