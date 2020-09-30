#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

#include "StoredWebPages.h"
#include "StringIntMap.h"
#include "StoredWords.h"

using namespace std;

/* TEMP */
int tmpAlloc = 180 - 000;
StoredWebPages webPages(25000);
StoredWords storedWords(tmpAlloc);
StringIntMap webPageIntMap;
StringIntMap wordIntMap;
auto *wordOnPage = new StringIntMap;
std::vector<StoredWebPages::Webpage> pages = webPages.getWebPages();
std::vector<StoredWords::Word> everyDistinctWordVec = storedWords.getWords();
/* TEMP */

/* Returns entire file as one big string, quickly */

bool comparePageWeight(int a, int b) {
    return (a > b);
}

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
void predict(const string &query) {
    cout << color_green << "Search keyword: '"
         << color_white << query
         << color_green << "' should go\n";

    /* TEST CODE */
//    int myLookUp = wordIntMap[query];
//    cout << everyDistinctWordVec.at(myLookUp).text << endl;
//    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;
//    cout << "5 webpages "<<endl;
//    for (int i = 0; i < everyDistinctWordVec.at(myLookUp).pages.size(); i++) {
//        int link = everyDistinctWordVec.at(myLookUp).pages.at(i);
//        cout << "LINK: "<<pages.at(link).url << endl;
//        cout << "";
//        if (i == 5) {
//            break;
//        }
//    }
    /* TEST CODE */
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

/*Toy with preAlloc memory */
int main() {
//    StoredWebPages webPages(25000);
//    StoredWords storedWords(tmpAlloc);
//    StringIntMap webPageIntMap;
//    StringIntMap wordIntMap;
//    auto *wordOnPage = new StringIntMap;
//    std::vector<StoredWebPages::Webpage> pages = webPages.getWebPages();
//    std::vector<StoredWords::Word> everyDistinctWordVec = storedWords.getWords();
    const char *filename = "/Users/gavintaylormcroy/Desktop/webpages.txt";
    string readInData;

    cout << color_green << "Reading input..." << endl;
    istringstream webFile(readWebpagesFast(filename));

    /* Insert all PAGES and DISTINCT words into separate hash table */
    {
        int totalWebPages = 0;
        int totalDistinctWords = 0;
        while (webFile >> readInData) {
            if (readInData == "PAGE") {
                webFile >> readInData;
                webPageIntMap.insert(readInData, totalWebPages);
                totalWebPages++;
            } else if (readInData == "LINK ") {
                /* This is catching the hyper link and just trashing it */
                webFile >> readInData;
            } else {
                /* Store all the DISTINCT words in a map/hash table THAT containing
                 * the words INDEX/POS for the words INSIDE the vector located in StoredWords */
                if (!wordIntMap.find(readInData)) {
                    wordIntMap.insert(readInData, totalDistinctWords);
                    /* This is adding the words to the vector */
                    everyDistinctWordVec.emplace_back(readInData);
                    totalDistinctWords++;
                }
            }
        }
    }
    cout << "Indexing..." << endl;

    /* Reset the file being read */
    webFile.clear();
    webFile.seekg(0);

    /* 26,881 Pages, 184,408 Hyperlinks, 18,896,392 words */

    /* This builds our webpage vector with all appropriate info */
    {
        string url;
        int numLinksOnPageCounter = 0;
        int numWordsOnPageCounter = 0;
        int uniqueWordsOnPageCounter = 0;
        bool firstIteration = true;
        vector<int> links;
        vector<string> wordsOccurringInPage;

        while (webFile >> readInData) {
            if (readInData == "PAGE") {
                if (!firstIteration) {
                    /* Reset all the counters by adding the WebPage + all its data */
                    pages.emplace_back(url, numLinksOnPageCounter, numWordsOnPageCounter, links, wordsOccurringInPage);
                    wordOnPage->~StringIntMap();
                    wordOnPage = new StringIntMap();
                    wordsOccurringInPage.clear();
                    links.clear();
                    numLinksOnPageCounter = 0;
                    numWordsOnPageCounter = 0;
                    uniqueWordsOnPageCounter = 0;
                    /* Reset all the counters */
                }
                firstIteration = false;
                /* Read in because you want the PAGE then the url next to it */
                webFile >> url;
            }
                /* Reads a hyperLink, calculates the index at which the hyperLink would exist inside inside the StringToIntMap
                * hash table. It then determines if the hyperLink in question exists inside the hash table. If it exists
                * inside the hash table, a reference value is given that corresponds to the index at which this link
                * would exist inside the Vector of WebPages. Reference value is given on first file read */
            else if (readInData == "LINK") {
                /* Read in because you want LINK then the url next to it */
                webFile >> readInData;
                /* If the link is not a dead end */
                if (webPageIntMap.find(readInData)) {
                    int location = webPageIntMap[readInData];
                    links.push_back(location);
                    numLinksOnPageCounter++;
                }
            } /* All other words are processed */
            else {
                /* These are the words that OCCUR within a particular page */
                wordsOccurringInPage.push_back(readInData);
                numWordsOnPageCounter++;
                /* This is adding only non duplicate words from a particular page*/
                if (!wordOnPage->find(readInData)) {
                    /* A lot is happening here. We are taking the index at which the page exists
                    * in the page structure. Then getting the index at which the word exists in the word structure.
                    * then we are accessing the index at which the word exists, adding the index at which the link exists
                    * to the word struct. Then while inside the word struct we are incrementing num pages to signify
                    * how many pages the word is on*/
                    wordOnPage->insert(readInData, uniqueWordsOnPageCounter);
                    int linkIndex = webPageIntMap[url];
                    int wordIndex = wordIntMap[readInData];
                    everyDistinctWordVec.at(wordIndex).pages.push_back(linkIndex);
                    everyDistinctWordVec.at(wordIndex).numPages++;
                    uniqueWordsOnPageCounter++;
                }
            }
        }
    }

    /* TEST SEARCH */
    int myLookUp = wordIntMap["dabo"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;

    myLookUp = wordIntMap["football"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;

    myLookUp = wordIntMap["pancakes"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;

    myLookUp = wordIntMap["pancake"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    cout << "Total Pages " << everyDistinctWordVec.at(myLookUp).numPages << endl;
    /* TEST SEARCH */

    /* GOOGLE PAGE RANK */
    std::cout << "Google page rank" << endl;

    for (int x = 0; x < 50; x++) {
        for (auto &page : pages) {
            page.newWeight = .1; /* change to newWeight */
        }
        for (int i = 0; i < pages.size(); i++) {
            /* Every page that pages.at(j) links too*/
            if (pages.at(i).links.empty()) {
                pages.at(i).newWeight += .9 * pages.at(i).weight;
            } else {
                for (int j = 0; j < pages.at(i).links.size(); j++) {
                    /* pages.at(j).links.at(k); */
                    /*
                    Increase new_weight[j] by 0.9 * pages[i].weight / pages[i].num_links
                    (this spreads 90% of the weight of a page uniformly across its
                    outgoing links. As a special case, if page i has no outgoing links,
                    please keep that 90% on the page by increasing new_weight[i] by
                    pages[i].weight * 0.9)
                     */

                    int index = pages.at(i).links.at(j) - 1;

                    try {
                        pages.at(index).newWeight += (.9 * pages.at(i).weight) / (double) pages.at(
                                i).links.size();     // vector::at throws an out-of-range
                    }
                    catch (const std::out_of_range &oor) {
                        std::cerr << "Out of Range error: " << oor.what() << '\n';
                        std::cout << "INDEX VALUE = " << index << endl;
                        std::cout << " I = " << i << endl;
                        std::cout << "J = " << j << endl;
                    }
                    // pages.at(index).newWeight += (.9 * pages.at(i).weight) / (double) pages.at(i).numLinks;

                }
            }
        }

        for (int i = 0; i < pages.size(); i++) {
            pages.at(i).weight = pages.at(i).newWeight;
            /*
            For each page i, set pages[i].weight = new_weight[i].
                    (note that these are three separate "for each page i" loops, one after
            the other. also note that weights on pages are never created or destroyed
            in each iteration of Pagerank --- they are only redistributed, so the
            total of all the weights should always be 1).
             */
        }
    }

    myLookUp = wordIntMap["pancake"];
    cout << everyDistinctWordVec.at(myLookUp).text << endl;
    int tmp = everyDistinctWordVec.at(myLookUp).pages.at(0);
    cout << pages.at(tmp).weight << endl;
    tmp = everyDistinctWordVec.at(myLookUp).pages.at(1);
    cout << pages.at(tmp).weight << endl;
    tmp = everyDistinctWordVec.at(myLookUp).pages.at(2);
    cout << pages.at(tmp).weight << endl;
    tmp = everyDistinctWordVec.at(myLookUp).pages.at(3);
    cout << pages.at(tmp).weight << endl;
    tmp = everyDistinctWordVec.at(myLookUp).pages.at(4);
    cout << pages.at(tmp).weight << endl;
    tmp = everyDistinctWordVec.at(myLookUp).pages.at(5);
    cout << pages.at(tmp).weight << endl;


    cout << "Finished" << endl;
    delete wordOnPage;

    /* Enter loop to ask for query */
    processKeystrokes();

    return 0;
}

/** Note I could insert these string values of page into the hash table
 * then when I am checking all my hyper links I can call find. If I find it
 * I can check its location, and store the corresponding location inside of
 * my vector<int> */

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


/*Reset File Read */
//    webfile.clear();
//    webfile.seekg(0);

/*  std::string text;
    int numPages;
    std::vector<int> pages; */

//    while (webfile >> readInValue) {
//        if (readInValue == "PAGE") {
//            /* This variable is helpful for grabbing the link index  */
//            webfile >> url;
//        } else if (readInValue == "LINK") {
//            /* Trash the link associated with page  */
//            webfile >> readInValue;
//        } else {
//            /* A lot is happening here. We are taking the index at which the page exists
//             * in the page structure. Then getting the index at which the word exists in the word structure.
//             * then we are accessing the index at which the word exists, adding the index at which the link exists
//             * to the word struct. Then while inside the word struct we are incrementing num pages to signify
//             * how many pages the word is on*/
//            int linkIndex = webPageIntMap[url];
//            int wordIndex = wordIntMap[readInValue];
//            words.at(wordIndex).pages.push_back(linkIndex);
//            words.at(wordIndex).numPages++;
//            //pagesThatContainWord.push_back(index);
//            /* This is all the words in the entire file */
//        }
//    }

/* DEBUG */
//    for (int i = 0; i < everyDistinctWordVec.at(myLookUp).pages.size(); i++) {
//        cout << everyDistinctWordVec.at(myLookUp).pages.at(i) << endl;
//    }


//    cout << pages.at(0).url << endl;
//    cout << pages.at(0).numLinks << endl;
//
//    cout << pages.at(0).words.size() << endl;
//    cout << pages.at(0).words.at(0) << endl;
/* DEBUG */