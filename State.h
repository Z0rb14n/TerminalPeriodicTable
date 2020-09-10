#ifndef STATE_H
#define STATE_H

#include <string>

enum State { Solid,Liquid,Gas, StateUnknown };

/**
Converts State s to string
*/
std::string antiParseState(State s);

State strState(std::string a);

#endif