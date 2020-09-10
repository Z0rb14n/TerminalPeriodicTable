#ifndef GROUP_NUM_H
#define GROUP_NUM_H

#include <string>

struct GroupNum{
    unsigned int number = 69; // 1 - 18
    std::string str; // either Other or Unknown
    std::string antiParse();
    GroupNum();
    GroupNum(int a);
    GroupNum(std::string a);
    GroupNum(std::string a, int b);
};

#endif