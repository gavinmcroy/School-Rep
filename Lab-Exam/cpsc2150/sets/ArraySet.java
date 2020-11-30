package cpsc2150.sets;

import java.util.Random;

public class ArraySet<T> extends SetAbs<T> implements ISet<T> {

    /**
     * Correspondences size = arraySize and self = myArraySet
     *
     * @invariants [set contains no duplicate values]
     */
    private int setSize;
    private final T[] myArraySet;


    /**
     * Values inside the array are set to be null
     *
     * @post: [Set is empty] (represented by each value being null)
     */
    public ArraySet() {
        myArraySet = (T[]) new Object[ISet.MAX_SIZE];
        for (int i = 0; i < ISet.MAX_SIZE; i++) {
            myArraySet[i] = null;
        }
        setSize = 0;
    }


    /**
     * This method adds a new value in the set.
     *
     * @param val the value to add to the set
     * @pre !contains(val) and size < MAX_SIZE
     * @post [val is added to the set]
     */
    @Override
    public void add(T val) {
        myArraySet[setSize] = val;
        setSize++;
    }

    /**
     * This method removes a value from the set
     *
     * @return the value removed from the set
     * @pre size > 0
     * @post: remove = [a value from the set] and self = #self - remove
     */
    @Override
    public T remove() {
        Random rand = new Random();
        int r_num = rand.nextInt(this.getSize());
        T myParam = myArraySet[r_num];
        setSize--;
        myArraySet[r_num] = null;
        return myParam;
    }

    /**
     * This method checks to see if a value exists in the set
     *
     * @param val a value to check
     * @return whether or not val is in the set
     * @pre none needed
     * @post contains iff [val is in self]
     */
    @Override
    public boolean contains(T val) {
        for(int i = 0; i < ISet.MAX_SIZE; i++){
            if(myArraySet[i].equals(val)){
                return true;
            }
        }
        return false;
    }

    /**
     * This method returns the size of the set
     *
     * @return the size of the set
     * @pre none needed
     * @post getSize = size
     */
    @Override
    public int getSize() {
        return setSize;
    }
}
