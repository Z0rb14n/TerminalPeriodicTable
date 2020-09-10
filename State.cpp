#include <string>
#include <stdexcept>
#include "State.h"

std::string antiParseState(State s){
    if (s == Solid) return "Solid";
    if (s == Liquid) return "Liquid";
    if (s == Gas) return "Gas";
    if (s == StateUnknown) return "Unknown";
    else throw std::invalid_argument("how did you screw up an enum for state boi");
}
State strState(std::string a){
    if (a == "S") return Solid;
    if (a == "L") return Liquid;
    if (a == "G") return Gas;
    if (a == "U") return StateUnknown;
    throw std::invalid_argument("Invalid argument for strState(). Note: has to be a capital letter of S/L/G/U.");
}