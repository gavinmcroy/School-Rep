#include <iostream>
#include<fstream>
#include <sstream>
#include "TweetParser.h"


int main(int argc, char* argv[]) {
    std::string argument;
    argument.append(argv[1]);
    TweetParser tweetParser(argument);
    return 0;
}
