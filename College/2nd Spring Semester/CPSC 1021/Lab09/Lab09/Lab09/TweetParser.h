//
// Created by Gavin Taylor Mcroy on 3/12/2020 AD.
//

#include<string>
#include <vector>
#ifndef LAB09_TWEETPARSER_H
#define LAB09_TWEETPARSER_H


class TweetParser {
private:
    struct TweetData{
        std::string reportType;
        std::string detail;
        std::string location;
        std::string latitude;
        std::string longitude;
    };
    std::vector<TweetData> tweets;
    std::ifstream inputFile;

public:
    TweetParser(std::string);

    void openFile(std::string);

    void readData();

    void printData();

    void closeFile();


};


#endif //LAB09_TWEETPARSER_H
