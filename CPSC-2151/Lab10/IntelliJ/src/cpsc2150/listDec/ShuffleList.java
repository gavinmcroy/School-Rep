package cpsc2150.listDec;

import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.Collection;

/**
 * @Correspondence: self = myList
 * @Invariant: 0 <= myList.size()
 * @param <T>
 */
public class ShuffleList<T> implements IShuffleList<T> {
    List<T> myList;

    /**
     * Sets myList to l
     * @param l
     * @pre l is not NULL
     * @post myList = l
     */
    public ShuffleList(List<T> l) {
        myList = l;
    }

    /**
     * Appends the specified element to the end of this list (optional
     * operation.
     * @param e element to be appended to this list
     * @return true iff successfully added
     * @pre e != NULL
     * @post |myList| = |#myList| + 1
     *       myList.get(myList.size()-1) = e
     */
    public boolean add(T e) {
        return myList.add(e);
    }

    /**
     * Returns the element at the specified position in this list.
     * @param i
     * @return element at i
     * @pre 0 <= i < |myList|, 0 < |myList|
     * @post |myList| = |#myList|, get(i) = myList at i
     */
    public T get(int i) {
        return myList.get(i);
    }

    /**
     * Adds e at index
     * @param index, index in myList
     * @param e, element to add
     * @pre 0<= index <= |myList|, e!=NULL
     * @post | myList | = | # myList | + 1
     * myList.get(index) = e
     */
    public void add(int index, T e) {
        myList.add(index, e);
    }

    /**
     * Returns the number of elements in this list.  If this list contains
     * more than
     * @return the number of elements in this list
     * @post size = |myList|
     */
    public int size() {
        return myList.size();
    }

    /**
     * Removes all of the elements from this list (optional operation).
     * The list will be empty after this call returns.
     * @post |myList| = 0
     */
    public void clear() {
        myList.clear();
    }

    /**
     * Replaces the element at the specified position in this list with the
     * specified element (optional operation).
     * @param i index of the element to replace
     * @param x element to be stored at the specified position
     * @return the element previously at the specified position
     * @pre 0 <= i < |myList|, x != NULL
     * @post |myList| = |#myList|, set = #myList.get(i), myList.get(i) = x
     */

    public T set(int i, T x) {
        return myList.set(i, x);
    }

    public List<T> subList(int i, int j) {
        return myList.subList(i, j);
    }

    public ListIterator<T> listIterator() {
        return myList.listIterator();
    }

    public ListIterator<T> listIterator(int i) {
        return myList.listIterator(i);
    }

    public int lastIndexOf(Object o) {
        return myList.lastIndexOf(o);
    }

    public int indexOf(Object o) {
        return myList.indexOf(o);
    }

    @Override
    public int hashCode() {
        return myList.hashCode();
    }

    @Override
    public boolean equals(Object o) {
        return myList.equals(o);
    }

    @Override
    public String toString() {
        return myList.toString();
    }

    public boolean addAll(Collection<? extends T> c) {
        return myList.addAll(c);
    }

    public boolean removeAll(Collection<?> c) {
        return myList.removeAll(c);
    }

    public boolean retainAll(Collection<?> c) {
        return myList.retainAll(c);
    }

    public boolean addAll(int i, Collection<? extends T> c) {
        return myList.addAll(i, c);
    }

    public boolean containsAll(Collection<?> c) {
        return myList.containsAll(c);
    }

    public T remove(int index) {
        return myList.remove(index);
    }

    public boolean remove(Object o) {
        return myList.remove(o);
    }

    public boolean isEmpty() {
        return myList.isEmpty();
    }

    public boolean contains(Object obj) {
        return myList.contains(obj);
    }

    public Iterator<T> iterator() {
        return myList.iterator();
    }

    public Object[] toArray() {
        return myList.toArray();
    }


    public Object[] toArray(Object[] ts) {
        return myList.toArray(ts);
    }
}
