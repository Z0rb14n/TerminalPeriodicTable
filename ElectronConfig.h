#ifndef ELECTRON_CONFIG_H
#define ELECTRON_CONFIG_H

#include <string>

struct ElectronConfig{
    std::string first;
    unsigned int num = 69;
    std::string antiParse();
    ElectronConfig(std::string a);
    static bool validEConfig(std::string a);
};

#endif