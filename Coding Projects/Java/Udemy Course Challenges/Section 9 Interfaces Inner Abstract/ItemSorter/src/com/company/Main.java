package com.company;

public class Main {

    public static void main(String[] args) {
        SearchTree tree = new SearchTree(null);
        tree.transverse(tree.getRoot());

        String stringData = "Brisbane Perth Melbourne Darwin Darwin";

//        String stringData = "5 7 3 9 8 2 1 0 4 6";
        String[] data = stringData.split(" ");
        for (String s : data) {
            tree.addItem(new Node(s));
        }

        tree.transverse(tree.getRoot());
    }
}
