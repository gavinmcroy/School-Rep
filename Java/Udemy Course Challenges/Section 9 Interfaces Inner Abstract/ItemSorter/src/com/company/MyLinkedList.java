package com.company;

public class MyLinkedList implements NodeList {

    private ListItem root;

    public MyLinkedList(ListItem root) {
        this.root = root;
    }

    @Override
    public ListItem getRoot() {
        return this.root;
    }

    @Override
    public boolean addItem(ListItem newItem) {
        if (this.root == null) {
            //---list empty so this becomes head of list
            this.root = newItem;
            return true;
        }
        ListItem currentItem = this.root;
        while (currentItem != null) {
            int comparison = currentItem.compareTo(newItem);
            if (comparison < 0) {
                //---new item is greater move to next
                if (currentItem.next() != null) {
                    currentItem = currentItem.next();
                } else {
                    //---There is no next so insert at end of list
                    currentItem.setNext(newItem).setPrevious(currentItem);
                    return true;
                }
            } else if (comparison > 0) {
                //---new item is less move to previous
                if (currentItem.previous() != null) {
                    currentItem.previous().setNext(newItem).setPrevious(currentItem.previous());
                    newItem.setNext(currentItem).setPrevious(newItem);
                } else {
                    //---node with a previous is the root
                    newItem.setNext(this.root).setPrevious(newItem);
                    this.root = newItem;
                }
                return true;
            } else {
                //---Equal
                System.out.println(newItem.getValue() + " already exists");
                return false;
            }
        }
        return false;
    }


    @Override
    public boolean removeItem(ListItem item) {
        if (item != null) {
            System.out.println(" Deleting item: " + item.getValue());
        }
        ListItem currentItem = this.root;
        while (currentItem != null) {
            int comparison = currentItem.compareTo(item);
            if (comparison == 0) {
                //---Found item to delete
                if (currentItem == this.root) {
                    this.root = currentItem.next();
                } else {
                    currentItem.previous().setNext(currentItem.next);
                    if (currentItem.next() != null) {
                        currentItem.next.setPrevious(currentItem.previous());
                    }
                }
                return true;
            } else if (comparison < 0) {
                currentItem = currentItem.next();
            } else {
                //---Comparison > 0
                //---At an item greater than the one to be deleted so Item is not in list
                return false;
            }
        }
        //---Reached end of list without finding item
        return false;
    }

    @Override
    public void transverse(ListItem root) {
        if (root == null) {
            System.out.println("List is empty");
        } else {
            while (root != null) {
                System.out.println(root.getValue());
                root = root.next();
            }
        }

//        if(root!=null){
//            System.out.println(root.getValue());
//            transverse(root.next());
//        }
    }
}
