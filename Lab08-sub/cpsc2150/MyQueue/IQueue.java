package cpsc2150.MyQueue;

public interface IQueue<T> {
    /**
     * A queue containing objects, T.
     * A queue is a data structure where the first item added to the
     * structure is the first item removed from the structure
     *
     * Defines: length: Z
     * Constraints: 0 <= length of a self <= MAX_LENGTH
     * Initialization Ensures: Queue is empty
     */

    public static final int MAX_LENGTH = 100;

    /**
     * Adds x to end of self
     * @param x T to be added to end of self
     * @pre length < MAX_LENGTH
     * @post length = #length + 1, self[length-1] = x
     */
    public void enqueue(T x);


    /**
     * removes and returns T at the front of the self
     * @return T at front of self
     * @pre length > 0
     * @post length = #length - 1, self[i] = #self[i+1]
     */
    public T dequeue();


    /**
     * @return length, the number of T's in self
     * @post length() = length
     *       self = #self
     */
    public int length();


    /**
     * clears the entire queue
     * @post length = 0, self is empty
     */
    public void clear();


    /**
     *
     * @return T at front of self
     * @pre length > 0
     * @post length = #length, self = #self, peek() = self[0]
     */
    default public T peek(){
        T front = dequeue(); //get first
        enqueue(front); //add back to end
        for (int i=0; i<(length()-1); i++){
            T temp = dequeue(); //remove from front
            enqueue(temp); //add back to end
        }
        return front;
    }

    /**
     *
     * @return T at end of queue
     * @pre length > 0
     * @post length = #length, self = #self, endOfQueue = self[length-1]
     */
    default public T endOfQueue(){
        for (int i=0; i<(length()-1); i++){
            T temp = dequeue();
            enqueue(temp);
        }
        //first element is now the original last element
        T end = dequeue();
        enqueue(end); //put last element back at the end
        return end;
    }

    /**
     * inserts x at position pos in self
     * @pre pos < length <= MAX_LENGTH, 0<pos<MAX_LENGTH
     * @post length = #length + 1, #self[x] = pos
     */
    default public void insert(T x, int pos){
        for (int i=1; i<pos; i++){
            T temp = dequeue(); //pop of elements before insert
            enqueue(temp); //add them to end
        }
        enqueue(x); //add new element to end
        for (int i=0; i<(length()-pos); i++){
            //add elements after insert to end to maintain order
            T temp = dequeue();
            enqueue(temp);
        }
    }

    /**
     * returns and removes T at position pos in self
     * @return T at position pos
     * @pre length > pos, 0<pos<MAX_LENGTH
     * @post length = #length -1, self = #self - #self[pos],
     *       remove() = #self[pos]
     */
    default public T remove(int pos){
        for (int i=1; i<pos; i++){
            T temp = dequeue(); //pop of elements before insert
            enqueue(temp); //add them to end
        }
        T trash = dequeue();
        for (int i=0; i<=(length()-pos); i++){
            //add elements after insert to end to maintain order
            T temp = dequeue();
            enqueue(temp);
        }
        return trash;
    }

    /**
     * @return T at position pos in self
     * @pre length > pos, 0<pos<=MAX_LENGTH
     * @post length = #length, self = #self, get() = self[pos]
     */
    default public T get(int pos){
        for (int i=1; i<pos; i++){
            T temp = dequeue(); //pop of elements before insert
            enqueue(temp); //add them to end
        }

        T got = dequeue(); //grab element at position
        enqueue(got); //add it back to maintain order

        for (int i=0; i<(length()-pos); i++){
            //add elements after insert to end to maintain order
            T temp = dequeue();
            enqueue(temp);
        }
        return got;
    }
}
