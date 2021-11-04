#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int main() {
    int numTimes = 0;

    std::map<char, int> table;

    std::string alphabet;
    std::string word;
    cin >> numTimes;
    for (int i = 0; i < numTimes; i++) {
        cin >> alphabet >> word;
        for (int j = 0; j < alphabet.size(); j++) {
            table[alphabet[j]] = j;
        }
        int summation = 0;
        for (int j = 0; j < word.size() - 1; j++) {
            summation += abs(table[word[j]] - table[word[j + 1]]);
        }
        std::cout << summation << std::endl;
    }

    return 0;
}