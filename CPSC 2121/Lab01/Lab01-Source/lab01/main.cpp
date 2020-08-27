#include <string>
#include <iostream>
#include "intset.h"

using namespace std;

int main(void) {
    Intset I;
    string command;
    int key;

    I.insert(10);
    I.insert(9);
    I.insert(8);
    I.insert(7);
    I.insert(6);
    I.insert(5);
    I.insert(3);
    I.insert(2);
    I.insert(1);
    I.print();
    cout<<"SEARCH RESULT: "<<I.find(34)<<endl;

//    while (1) {
//
//        cin >> command;
//        if (cin.eof()) break;
//
//        if (command == "insert") {
//
//            cin >> key;
//            if (I.find(key))
//                cout << "Error!  Key " << key << " already in structure!\n";
//            else
//                I.insert(key);
//
//        } else if (command == "remove") {
//
//            cin >> key;
//            if (!I.find(key))
//                cout << "Error!  Key " << key << " not in structure!\n";
//            else
//                I.remove(key);
//
//        } else if (command == "find") {
//
//            cin >> key;
//            if (I.find(key))
//                cout << "Key " << key << " present.\n";
//            else
//                cout << "Key " << key << " absent.\n";
//
//        } else if (command == "print") {
//
//            cout << "Contents of structure in sorted order:\n";
//            I.print();
//
//        } else if (command == "quit") {
//
//            break;
//
//        } else {
//
//            cout << "Error!  Unknown command '" << command << "'!\n";
//
//        }
//    }

    return 0;
}
