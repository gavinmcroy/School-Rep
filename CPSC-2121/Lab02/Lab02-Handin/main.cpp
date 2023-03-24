#include <string>
#include <fstream>
#include <iostream>
#include "stringset.h"

using namespace std;

void spellcheck(void) {
    Stringset S;
    string word;

    ifstream wordfile("words.txt");
    while (wordfile >> word)
        S.insert(word);
    wordfile.close();

    cout << "Dictionary loaded.  Please enter words to spell check.\n";

    while (cin >> word) {
        cout << "Possible alternatives for word '" << word << "':\n";
        /* print out all words that differ by exactly one character */
        string searchedWord = word;
        for (unsigned int i = 0; i < word.size(); i++) {
            char temp = word[i];
            for (char j = 'a'; j <= 'z'; j++) {
                word[i] = j;
                if (S.find(word) && (word != searchedWord)) {
                    cout << word << endl;
                }
            }
            word[i] = temp;
        }
    }
}

void test(void) {
    Stringset S;
    string key, command;

    while (cin >> command) {

        if (command == "insert") {

            cin >> key;
            if (S.find(key))
                cout << "Error!  Key " << key << " already in structure!\n";
            else
                S.insert(key);

        } else if (command == "remove") {

            cin >> key;
            if (!S.find(key))
                cout << "Error!  Key " << key << " not in structure!\n";
            else
                S.remove(key);

        } else if (command == "find") {

            cin >> key;
            if (S.find(key))
                cout << "Key " << key << " present.\n";
            else
                cout << "Key " << key << " absent.\n";

        } else if (command == "print") {

            cout << "Contents of structure:\n";
            S.print();

        } else if (command == "quit") {

            break;

        } else {

            cout << "Error!  Unknown command '" << command << "'!\n";

        }
    }
}

int main(void) {
    //test();
    spellcheck();
    return 0;
}
