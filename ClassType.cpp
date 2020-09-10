#include <string>
#include <stdexcept>
#include "ClassType.h"

std::string antiClassType(ClassType c){
    if (c == Metal) return "Metal";
    if (c == Non_metal) return "Non metal";
    if (c == Metalloid) return "Metalloid";
    if (c == ClassUnknown) return "Unknown";
    throw std::invalid_argument("how did you screw up an enum for classtype boi");
}
ClassType strClassType(std::string a){
    if (a == "M") return Metal;
    if (a == "N") return Non_metal;
    if (a == "D") return Metalloid;
    if (a == "U") return ClassUnknown;
    throw std::invalid_argument("Invalid argument for strClassType(). Note: has to be a capital letter of M/N/D/U.");
}