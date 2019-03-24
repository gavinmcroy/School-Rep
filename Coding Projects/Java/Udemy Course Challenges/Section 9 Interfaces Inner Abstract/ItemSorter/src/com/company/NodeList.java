package com.company;

public interface NodeList {

    ListItem getRoot();

    boolean addItem(ListItem newItem);

    boolean removeItem(ListItem item);

    void transverse(ListItem root);


}
