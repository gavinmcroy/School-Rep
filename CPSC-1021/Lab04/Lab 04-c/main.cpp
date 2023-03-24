// included needed libraries here
#include<iostream>
#include "linkedlist.h"

using namespace std;

int main() {
//    int a = 20;
//    int b = 25;
//    int c = 30;
//
//    int* ptr_a = &a;
//    int* ptr_b = &b;
//    int* ptr_c = &c;
//    int* duplicate = ptr_a;
//
//    cout << "PTR A: " <<ptr_a <<"PTR DUPLICATE "<<duplicate<<endl;
//    ptr_a = ptr_b;
//    cout << "PTR A: " <<ptr_a <<"PTR DUPLICATE "<<duplicate<<endl;

    NodePtr newNode = NULL;

    // after you implemented your functions in .cpp file
    // - use the code below for testing your linked list.
    // Demonstrate that ALL functions are working correctly.

    // After that add code for reading data from input file.
    // Every time you read an integer, create a node and insert it
    // in the ascending order into the list.

    // At the end print the entire list to show that your code
    // functions correctly.
    std::vector<int>::iterator iter;
    int num;

    FILE *fptr;

    // make sure file exists, give message and exit otherwise
    if ((fptr = fopen("input.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

    // while we still have items to read
    while (fscanf(fptr, "%d", &num) != EOF) {
        //printf("n is:  %d\n", num);
        newNode = makeNewNode(num);
        insertAtEnd(newNode);
    }

    fclose(fptr);  // close the file

    //---Read from file and insert to front
//    for (int i = 0; i < 5; i++) {
//        newNode = makeNewNode(i);
//        insertAtFront(newNode);
//    }

    printList();

    cout << "After DeleteFromFront: " << endl;
    deleteFromFront();
    printList();

    NodePtr seven = makeNewNode(7);
    insertAtEnd(seven);
    cout << "Inserting seven at END" << endl;
    printList();

    NodePtr eight = makeNewNode(8);
    insertAtEnd(eight);
    cout << "Inserting eight at END" << endl;
    printList();

    cout << "After deleting eight: " << endl;
    deleteFromEnd();
    printList();

    cout << "After deleting seven:" << endl;
    deleteFromEnd();
    printList();


    return 0;
}
