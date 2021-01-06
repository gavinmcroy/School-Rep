package cpsc2150.sets;

/**
 * Sets are an unordered collection that does not allow duplicate values.
 * <p>
 * Defines:
 * size: Z - how many items are in the set
 * Initialization Ensures:
 * the set is empty and size = 0
 * Constraints:
 * [self contains no duplicate values]
 */
public interface ISet<T> {

    /**
     * Maximum size of {@link ISet}
     */
    int MAX_SIZE = 100;
    int LOOP_VAL = 10000;

    /**
     * This method adds a new value in the set.
     *
     * @param val the value to add to the set
     * @pre !contains(val) and size < MAX_SIZE
     * @post [val is added to the set]
     */
    void add(T val);

    /**
     * This method removes a value from the set
     *
     * @return the value removed from the set
     * @pre size > 0
     * @post: remove = [a value from the set] and self = #self - remove
     */
    T remove();

    /**
     * This method checks to see if a value exists in the set
     *
     * @param val a value to check
     * @return whether or not val is in the set
     * @pre none needed
     * @post contains iff [val is in self]
     */
    boolean contains(T val);

    /**
     * This method returns the size of the set
     *
     * @return the size of the set
     * @pre none needed
     * @post getSize = size
     */
    int getSize();

    /**
     * This method unions two sets
     *
     * @param unionWith the set to union with
     * @pre self.getSize() + unionWith.getSize() <= MAX_SIZE
     * @post self = #self U #unionWith
     */
    default void union(ISet unionWith) {
        for (Integer i = 0; i < LOOP_VAL; i++) {
            if (!this.contains((T) i) && unionWith.contains(i) ) {
                this.add((T) i);
            }
        }
    }

    /**
     * This method intersects two sets
     *
     * @param intersectWith the set to intersect with
     * @post self = [the intersection of #self and #intersectWith]
     */
    default void intersect(ISet intersectWith) {
        ISet<T> myTmp = new ArraySet<>();
        for (Integer i = 0; i < LOOP_VAL; i++) {
            if (this.contains((T) i) && intersectWith.contains(i)) {
                myTmp.add((T)i);
            }
        }
//        for(int i = 0; i < getSize(); i++){
//            remove();
//        }
        for(Integer i = 0; i < LOOP_VAL; i++){
            if(this.contains((T) i) && myTmp.contains((T) i)){
                //---DO not add duplicates
            }else if(!this.contains((T)i) && myTmp.contains((T)i)){
                this.add((T)i);
            }
        }
    }
}