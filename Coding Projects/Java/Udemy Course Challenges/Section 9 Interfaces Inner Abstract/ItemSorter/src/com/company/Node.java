package com.company;

public class Node extends ListItem {

    public Node(Object value) {
        super(value);
    }

    @Override
    public ListItem next() {
        return this.next;
    }

    @Override
    public ListItem setNext(ListItem item) {
        this.next = item;
        return this.next;
    }

    @Override
    public ListItem previous() {
        return this.previous;
    }

    @Override
    public ListItem setPrevious(ListItem item) {
        this.previous = item;
        return this.previous;
    }

    @Override
    public int compareTo(ListItem listitem) {
        if (listitem != null) {
            return ((String) super.getValue()).compareTo((String) listitem.getValue());
        } else {
            return -1;
        }
    }
}
