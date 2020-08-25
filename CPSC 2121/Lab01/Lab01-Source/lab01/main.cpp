#include <string>
#include <iostream>
#include "intset.h"

using namespace std;

int main(void) {
    Intset I;
    string command;
    int key;

    I.insert(10);
    I.insert(34);
    I.insert(35);
    I.insert(36);
    I.insert(37);
    I.insert(39);
    I.insert(40);
    I.print();
    cout<<I.find(41)<<endl;

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
