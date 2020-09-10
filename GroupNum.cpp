#include "GroupNum.h"

#include <iostream>
#include <string>
#include <stdexcept>

std::string GroupNum::antiParse() {
    if (number == 69 && str == "O") return "Other";
    else if (number != 69) return std::to_string (number);
    else throw std::invalid_argument("Invalid/uninitialized Group Number.");
}

GroupNum::GroupNum() {
  str = "";
  number = 69;
}

GroupNum::GroupNum(int a) {
    number = a;
    str = "";
}

GroupNum::GroupNum(std::string fatString){
  if (fatString == "O") {
    str = fatString;
    number = 69;
  } else {
    str = "";
    number = std::stoi(fatString);
  }
}
GroupNum::GroupNum(std::string a, int b){
    if (b == 69){
        str = a;
        number = 69;
    } else {
        str = "";
        number = b;
    }
}