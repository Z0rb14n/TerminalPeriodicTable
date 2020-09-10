#ifndef CLASS_TYPE_H
#define CLASS_TYPE_H

#include <string>

enum ClassType{ Metal, Non_metal, Metalloid, ClassUnknown };
std::string antiClassType(ClassType c);
ClassType strClassType(std::string a);

#endif