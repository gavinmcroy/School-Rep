#include <iostream>
#include<fstream>
#include "TweetParser.h"


int main(int argc, char* argv[]) {

    //---TODO Modify for file input
    std::cout<<argv[1]<<std::endl;
    int i = 0;
    std::string argument;
    while(true){
        if(argv[i]==nullptr){
            break;
        }
        argument.append(argv[i]);
        i++;
    }
    std::cout<<argument<<std::endl;
    //TweetParser tweetParser();
//    std::cout << "Hello, World!" << std::endl;
//    std::ifstream inFile("lab9_input.dms", std::ios::in);
//    if (inFile) {
//        std::cout << "File read successfully" << std::endl;
//    } else {
//        std::cout << "Critical error" << (inFile) << std::endl;
//    }
//    std::string tmp;
//
//
//    int i = 1;
//    while (getline(inFile, tmp)) {
//        std::stringstream stringStream(tmp);
//        std::string token;
//        while (getline(stringStream, token, '#')) {
//            int colon = token.find(';');
//            int space = token.find(' ');
//            std::string type;
//            std::string detail;
//            std::string location;
//            std::string latitude;
//            std::string longitude;
//
//            if (space < 0) {
//                continue;
//            }
//
//            if (token.length() <= 0) {
//                continue;
//            }
//            token = token.substr(0, colon);
//
//            if (i % 5 == 1) {
//                type = token.substr(space, token.length() - 1);
//                std::cout << "TYPE: " << type << std::endl;
//            } else if (i % 5 == 2) {
//                detail = token.substr(space, token.length() - 1);
//                std::cout << "DETAIL: " << detail << std::endl;
//            } else if (i % 5 == 3) {
//                location = token.substr(space, token.length() - 1);
//                std::cout << "LOCATION: " << location << std::endl;
//            } else if (i % 5 == 4) {
//                latitude = token.substr(space, token.length() - 1);
//                std::cout << "LATITUDE: " << latitude << std::endl;
//            } else if (i % 5 == 0) {
//                longitude = token.substr(space, token.length() - 1);
//                std::cout << "LONGITUDE: " << longitude << std::endl;
//                std::cout << std::endl;
//            }
//
//            i++;
//        }
//    }
    return 0;
}
