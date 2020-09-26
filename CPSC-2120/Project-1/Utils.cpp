#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

#include "StoredWebPages.h"
#include "StringIntMap.h"

using namespace std;

/** WHERE I LEFT OFF
 *
 *              */


/* Returns entire file as one big string, quickly */
string readWebpagesFast(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: can't open %s", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *buff = new char[size + 1];
    buff[size] = 0;
    int dummy_result = fread(buff, size, 1, fp);
    fclose(fp);
    string result(buff);
    delete[] buff;
    return result;
}

/* Some ANSI terminal commands you can print to clear screen and change colors */
string clear_screen = "\e[2J\e[H";
string color_red = "\e[31;40m";
string color_green = "\e[32;40m";
string color_yellow = "\e[33;40m";
string color_blue = "\e[34;40m";
string color_magenta = "\e[35;40m";
string color_cyan = "\e[36;40m";
string color_white = "\e[37;40m";
string color_whiteblue = "\e[37;44m";

/* TODO IMPLEMENT */
void predict(string query) {
    cout << color_green << "Here is where query results for '"
         << color_white << query
         << color_green << "' should go\n";
}

void processKeystrokes() {
    int ch = 0;
    string query;

    while (ch != '\n') {
        cout << clear_screen << color_green << "Search keyword: "
             << color_white << query
             << color_green << "-\n\n";

        predict(query);
        cout << flush;

        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        if (ch == 8 || ch == 127) { // backspace
            if (query.length() > 0) query = query.substr(0, query.length() - 1);
        } else if (ch != ' ' && ch != '\n') query += ch;
    }
    cout << color_white;
}

/* This shows how to use some of the starter code above */
int main() {
    StoredWebPages webPages;
    StringIntMap stringIntMap;

    cout << color_green << "Reading input..." << endl;
    const char *filename = "/Users/gavintaylormcroy/Desktop/webpages.txt";
    istringstream webfile(readWebpagesFast(filename));

    std::vector<StoredWebPages::Webpage> pages = webPages.getWebPages();

    /* I could insert these string values of page into the hash table
     * then when I am checking all my hyper links I can call find. If I find it
     * I can check its location, and store the corresponding location inside of
     * my vector<int> */

    /* Insert all PAGES into the hash table TODO the value 0 needs to be changed */
    int totalWebPages = 0;
    string n;
    while (webfile >> n) {
        if (n == "PAGE") {
            webfile >> n;
            stringIntMap.insert(n, totalWebPages);
            totalWebPages++;
        }

    }
    webfile.clear();
    webfile.seekg(0);

    /* 26,881 Pages, 184,408 Hyperlinks, 18,896,392 words */

    /* COUNTERS */
    string readInValue;
    string url;
    int numLinks = 0;
    int numWords = 0;
    vector<int> links;
    vector<string> wordsOccurringInPage;
    /* COUNTERS */

    /* Parameters */
    bool first = true;
    string hyperLink;
    /* Parameters */

    while (webfile >> readInValue) {
        if (readInValue == "PAGE") {
            if (!first) {
                /* Reset all the counters by adding the WebPage + all its data */
                pages.emplace_back(url, numLinks, numWords, links, wordsOccurringInPage);
                wordsOccurringInPage.clear();
                numLinks = 0;
                numWords = 0;
                /* Reset all the counters */
            }
            first = false;
            /* Read in because you want the PAGE then the url next to it */
            webfile >> url;

        } /* Reads a hyperLink, calculates the index at which the hyperLink would exist inside inside the StringToIntMap
           * hash table. It then determines if the hyperLink in question exists inside the hash table. If it exists
           * inside the hash table, a reference value is given that corresponds to the index at which this link
           * would exist inside the Vector of WebPages. Reference value is given on first file read */
        else if (readInValue == "LINK") {
            /* Read in because you want LINK then the url next to it */
            webfile >> hyperLink;
            if (stringIntMap.find(hyperLink)) {
                int hash = stringIntMap[hyperLink];
                links.push_back(hash);
                numLinks++;
            }
        } /* Regular Words are read in and added to the wordsOccurring vector*/
        else {
            wordsOccurringInPage.push_back(readInValue);
            numWords++;
        }
    }

    /* DEBUG */
    cout << pages.at(0).url << endl;
    cout << pages.at(0).numLinks << endl;

    cout << pages.at(0).words.size() << endl;
    cout << pages.at(0).words.at(0) << endl;
    /* DEBUG */


    // If you want to reset the webfile for reading again from the beginning...
    // webfile.clear();
    // webfile.seekg(0);
    // while (webfile >> s) ...

    // Enter loop to ask for query
    processKeystrokes();

    return 0;
}

/** REFERENCES */
//while (webfile >> s) {
//        if (s == "PAGE") {
//
//            /* Reset all the counters */
//            if (!first) {
//                pages.push_back(StoredWebPages::Webpage(url, numLinks, numWords,));
//            }
//            numLinks = 0;
//            numWords = 0;
//            /* Reset all the counters */
//            first = false;
//            webfile >> url;
//            numPages++;
//        } else if (s == "LINK") {
//            webfile >> hyperLink; /*(-THIS STRING NEEDS TO BE HASHED-) */
//            toBeHashed.push_back(hyperLink);
//            numLinks++;
//        } /* Regular Words */
//        else if (s != "LINK" && s != "PAGES") {
//            numWords++;
//        }
//    }
