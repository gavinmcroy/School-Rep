package cpsc2150.listDec;

import java.util.List;
import java.util.Random;

/**
 * @Defines: self
 * @Constraints: 0 < |self|
 * @Ensures: self is a list that is  not NULL
 *
 */

public interface IShuffleList<T> extends List<T> {

    /**
     * Shuffles a list by swapping elements swap number of times
     * @param swaps the number of swaps to perform
     * @pre 2 <= |self|
     * @post |self| = |#self|,
     *       [self is shuffled swap times]
     */
    default void shuffle(int swaps){
        for (int i=0; i<swaps; i++) {
            Random pos1 = new Random();
            Random pos2 = new Random();
            int pos1_int = pos1.nextInt(size());
            int pos2_int = pos2.nextInt(size());
            swap(pos1_int, pos2_int);
        }
    }

    /**
     * Swaps two elements in List
     * @param i, first index
     * @param j, second index
     * @pre 0 <= i < |self|, 0 <= j < |self|, 2 <= |self|
     * @post |self| = |#self|, self.get(i) = #self.get(j), self.get(j) = #self.get(i)
     */
    default void swap(int i, int j){
        T temp = get(i);
        set(i, get(j));
        set(j, temp);
    }

}
