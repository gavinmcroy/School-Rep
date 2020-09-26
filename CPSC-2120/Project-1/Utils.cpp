#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

#include "StoredWebPages.h"

using namespace std;

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
    StoredWebPages webPages(25);

    cout << color_green << "Reading input..." << endl;
    const char *filename = "/Users/gavintaylormcroy/Desktop/webpages.txt";

    istringstream webfile(readWebpagesFast(filename));

    std::vector<StoredWebPages::Webpage> pages = webPages.getWebPages();

    /* For now, this just counts the number of web pages in the input file... */
//    string s;
//    string page;
//    int N = 0;
//    while (webfile >> s)
//        if (s != "LINK" && s!="PAGE") {
//            //webfile >> s; // s is the url of the webpage currently being processed
//            N++;
//        }
//    cout<<N<<endl;


    /* 26,881 Pages, 184,408 Hyperlinks, 18,896,392 words */

    int numPages = 0;
    string s;
    string url;
    int numLinks = 0;
    int numWords = 0;
    vector<int> links;
    vector<string> words;

    vector<string> toBeHashed;
    string hyperLink;
    bool first = true;
    while (webfile >> s) {
        if (s == "PAGE") {

            /* Reset all the counters */
            if (!first) {
                pages.push_back(StoredWebPages::Webpage(url, numLinks, numWords,));
            }
            numLinks = 0;
            numWords = 0;
            /* Reset all the counters */
            first = false;
            webfile >> url;
            numPages++;
        } else if (s == "LINK") {
            webfile >> hyperLink; /*(-THIS STRING NEEDS TO BE HASHED-) */
            toBeHashed.push_back(hyperLink);
            numLinks++;
        } /* Regular Words */
        else if (s != "LINK" && s != "PAGES") {
            numWords++;
        }
    }

    cout << "NUM PAGES " << numPages << endl;
    cout << "NUM LINKS " << numLinks << endl;
    cout << "NUM WORDS " << numWords << endl;



    // If you want to reset the webfile for reading again from the beginning...
    // webfile.clear();
    // webfile.seekg(0);
    // while (webfile >> s) ...

    // Enter loop to ask for query
    processKeystrokes();

    return 0;
}
