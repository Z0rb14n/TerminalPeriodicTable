#include "ElectronConfig.h"
#include <string>
#include <stdexcept>

std::string ElectronConfig::antiParse() {
    if (num == 69 && first != "") return first;
    else if (first != "" && num != 69) return first + std::to_string(num);
    else throw std::invalid_argument("Invalid/uninitialized electron configuration.");
}

ElectronConfig::ElectronConfig(std::string a) {
    if (a.at(0) == '['){
        first = a;
        num = 69;
        return;
    }
    first = a.substr(0,2);
    if (a.length() == 3) num = a.at(2) - '0';
    else num = std::stoi(a.substr(2,2));
}

bool ElectronConfig::validEConfig(std::string a) {
    if (a.length() < 3 || a.length() > 4) return false;
    if (a.at(0) == '[' && a.at(3) == ']') return true;
    if (a.length() == 3) return (a.at(2) - '0' >= 0 && a.at(2) - '0' <= 9);
    if (a.length() == 4) {
        try{
            int ignored = std::stoi(a.substr(2,2));
            return true;
        } catch (std::exception& e){
            return false;
        }
    }
    return false;
}