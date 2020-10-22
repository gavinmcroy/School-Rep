package cpsc2150.MyQueue;

public abstract class AbsQueue<T> implements IQueue<T>{

    /**
     * @return comma-separated string of queue
     * @post toString = comma-separated string of queue
     */
    @Override
    public String toString(){
        String aString = "";
        for (int i=1; i<=length(); i++){
            aString = aString + get(i);
            if (i != length()){
                aString += ", ";
            }
        }
        return aString;
    }

}
