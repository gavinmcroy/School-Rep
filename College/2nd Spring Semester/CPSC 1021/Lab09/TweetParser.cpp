//
// Created by Gavin Taylor Mcroy on 3/12/2020 AD.
//
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<algorithm>

#include "TweetParser.h"

TweetParser::TweetParser(std::string fileName) {
    openFile(fileName);
    readData();
    printData();
    closeFile();
}

void TweetParser::openFile(std::string fileName) {
    inputFile.open(fileName, std::ios::in);
    if (inputFile) {
        std::cout << "Successfully opened file" << std::endl;
    } else {
        std::cout << "Error reading file " << std::endl;
        exit(1);
    }
}

void TweetParser::readData() {
    int i = 1;
    std::string tmp;
    TweetData tweetData;
    while (getline(inputFile, tmp)) {
        std::stringstream stringStream(tmp);
        std::string token;
        while (getline(stringStream, token, '#')) {
            int colon = token.find(';');
            int space = token.find(' ');


            if (space < 0) {
                continue;
            }

            if (token.length() <= 0) {
                continue;
            }
            token = token.substr(0, colon);

            if (i % 5 == 1) {
                tweetData.reportType = token.substr(space, token.length() - 1);
            } else if (i % 5 == 2) {
                tweetData.detail = token.substr(space, token.length() - 1);
            } else if (i % 5 == 3) {
                tweetData.location = token.substr(space, token.length() - 1);
            } else if (i % 5 == 4) {
                tweetData.latitude = token.substr(space, token.length() - 1);
            } else if (i % 5 == 0) {
                tweetData.longitude = token.substr(space, token.length() - 1);
                tweets.push_back(tweetData);
            }
            i++;
        }
    }
}

void TweetParser::printData() {
    for (int i = 0; i < tweets.size(); i++) {
        std::string tmpCache = tweets.at(i).reportType;
        for(char &c : tmpCache) c = toupper(c);
        std::cout << std::left << std::setw(12) << "TYPE: " << tmpCache << std::endl;
        std::cout << std::left << std::setw(12) << "DETAIL: " << tweets.at(i).detail << std::endl;
        std::cout << std::left << std::setw(12) << "LOCATION: " << tweets.at(i).location << std::endl;
        std::cout << std::left << std::setw(12) << "LATITUDE: " << tweets.at(i).latitude << std::endl;
        std::cout << std::left << std::setw(12) << "LONGITUDE: " << tweets.at(i).longitude << std::endl;
        std::cout<<std::endl;
    }
}

void TweetParser::closeFile() {
    inputFile.close();
}
