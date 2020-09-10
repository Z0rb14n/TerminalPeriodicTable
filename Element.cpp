//
//  Element.cpp
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-29.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#include "Element.h"
#include "GroupNum.h"
#include "GroupName.h"
#include "Block.h"
#include <vector>
#include "ElectronConfig.h"
#include <iostream>
#include <sstream>
#include <array>
#include <stdexcept>

Element::Element(std::string a, std::string b, unsigned int c, bool d, GroupNum e,GroupName l, Block f, unsigned int g, unsigned int h, double i,
        std::vector<ElectronConfig> j){
  name = a;
  symbol = b;
  period = c;
  isRadioactive = d;
  groupNum = e;
  groupName = l;
  block = f;
  atomicNumber = g;
  neutronNumber = h;
  approxAtomicMass = g+h;
  atomicMass = i;
  electron_Configuration = j;
}
Element::Element(std::string a, std::string b, unsigned int c, bool d, GroupNum e, Block f, unsigned int g,
        unsigned int h,
        double i,
        std::vector<ElectronConfig> j){
  name = a;
  symbol = b;
  period = c;
  isRadioactive = d;
  groupNum = e;
  groupName = groupToName(e);
  block = f;
  atomicNumber = g;
  neutronNumber = h;
  approxAtomicMass = g+h;
  atomicMass = i;
  electron_Configuration = j;
}
Element::Element(std::string fatString) {
  std::istringstream stream(fatString);
  //initialize string Group, Block, EConfig
  std::string fGroup /*convert this to group*/, fBlock /*Convert this to block*/;
  std::array<std::string, 6> strings_for_econfig;
  //stream input to variables
  stream >> name >> symbol >> period >> std::noboolalpha >> isRadioactive >> fGroup >> fBlock >> atomicNumber >> neutronNumber >> atomicMass;
  approxAtomicMass = neutronNumber + atomicNumber;
  for(int i = 0; i < 6; i++) stream >> strings_for_econfig[i];
  
  //check if valid
  if (atomicMass < 0.5 || fBlock == "" || fGroup == "" || period == 0 || atomicNumber == 0 || name == "" || symbol == ""|| (strings_for_econfig[0] == "" && strings_for_econfig[1] == "" && strings_for_econfig[2] == "" && strings_for_econfig[3] == "" && strings_for_econfig[4] == "" && strings_for_econfig[5] == "")) throw std::invalid_argument("Invalid data in data file, row: " + std::to_string(atomicNumber));
  
  //parse electron config
  for(int i = 0; i < 6; i++){
    if (strings_for_econfig[i].length() == 0) break;
    ElectronConfig eConfigTerm(strings_for_econfig[i]);
    electron_Configuration.push_back(eConfigTerm);
  }
  
  //parse Group
  std::string Group_Parse_String;
  unsigned int a = 69;
  if(fGroup == "O") Group_Parse_String = "O";
  else a = std::stoi(fGroup);
  groupNum = GroupNum(Group_Parse_String,a);
  block = strBlock(fBlock);
  fixGroupName();
}

void Element::fixGroupName(){
  if (atomicNumber < 57 || (atomicNumber > 71 && atomicNumber < 89) || atomicNumber > 103) return;
  if(period == 6){
    groupName = Lanthanide;
    if(atomicNumber != 57) groupNum.number = 69;
  } else {
    groupName = Actinide;
    if (atomicNumber != 89) groupNum.number = 69;
  }
}
std::string Element::antiParseEConfig(){
  std::string LOL;
  for(int i = 0; i < electron_Configuration.size(); i++){
    if (i == 0) LOL = electron_Configuration[i].antiParse();
    else LOL = LOL + " " + electron_Configuration[i].antiParse();
  }
  return LOL;
}
void Element::readElement(){
  std::cout << "Name:                     " << name << std::endl;
  std::cout << "Symbol:                   " << symbol << std::endl;
  std::cout << "Period:                   " << period << std::endl;
  std::cout << "Radioactive:              " << booleanString(isRadioactive) << std::endl;
  std::cout << "Group:                    " << groupNum.antiParse() << std::endl;
  std::cout << "Group Name:               " << groupNameString(groupName) << std::endl;
  std::cout << "Block:                    " << blockToString(block) << std::endl;
  std::cout << "Atomic Number:            " << atomicNumber << std::endl;
  std::cout << "Number of Neutrons:       " << neutronNumber << std::endl;
  if(approxAtomicMass == atomicMass) std::cout << "Approximate Mass:         " << approxAtomicMass << std::endl;
  else{
    std::cout << "Approximate Mass:         " << approxAtomicMass << std::endl;
    std::cout << "Actual Mass:              " << atomicMass << " amu" << std::endl;
  }
  std::cout << "Electronic Configuration: " << antiParseEConfig() << std::endl;
}
std::string Element::booleanString(bool value) {
  if (value) return "Yes";
  return "No";
}

bool Element::stringToBoolean(std::string value) {
  if (value == "0" || compare(value,"false")) return false;
  if (value == "1" || compare(value,"true")) return true;
  throw new std::invalid_argument("Invalid boolean " + value);
}

bool Element::compare(std::string a, std::string b){
  if(a.length() != b.length())return false;
  else{
    unsigned short int c =  a.length();
    for(int i = 0; i < c; i++) if(tolower(a.at(i)) != tolower(b.at(i))) return false;
  }
  return true;
}

void Element::edit(unsigned int valueToModify, std::string input) {
  switch (valueToModify) {
    case 1:
      name = input;
      break;
    case 2:
      symbol = input;
      break;
    case 3:
      isRadioactive = stringToBoolean(input);
      break;
    case 4: {
      unsigned int temp = std::stoi(input);
      if (temp < 1 || temp > 7) throw new std::invalid_argument("Invalid period number " + input);
      period = temp;
      break;
    }
    case 5: {
      if (compare(input,"other") || compare(input,"o")) {
        groupNum = GroupNum("O",69);
      } else {
        int integerInput = std::stoi(input);
        if (integerInput >= 18 && integerInput <= 18){
          groupNum = GroupNum("",integerInput);
        } else throw new std::invalid_argument("Invalid groupnumber: " + input);
      }
      break;
    }
    case 6:
      block = strBlock(input);
      break;
    case 7: {
      int integerInput = std::stoi(input);
      if (integerInput < 1) throw new std::invalid_argument("Invalid atomic number.");
      atomicNumber = integerInput;
      approxAtomicMass = neutronNumber + atomicNumber;
      break;
    }
    case 8: {
      int integerInput = std::stoi(input);
      if (integerInput < 0) throw new std::invalid_argument("Invalid number of neutrons");
      neutronNumber = integerInput;
      approxAtomicMass = neutronNumber + atomicNumber;
      break;
    }
    case 9: {
      double doubleInput = std::stod(input);
      if (doubleInput < 0) throw new std::invalid_argument("Invalid mass");
      atomicMass = doubleInput;
      break;
    }
    case 10: {
      std::istringstream stream(input);
      std::array<std::string, 6> stringsForEConfig;
      for (int i = 0; i < 6; i++) stream >> stringsForEConfig[i];
      electron_Configuration.clear();
      for(int i = 0; i < 6; i++){
        if (stringsForEConfig[i].length() == 0) break;
        ElectronConfig eConfigTerm(stringsForEConfig[i]);
        electron_Configuration.push_back(eConfigTerm);
      }
      break;
    }
    default:
      throw new std::invalid_argument("Invalid part of element to to modify: " + std::to_string(valueToModify));
  }
  
}

std::string Element::serialize() {
  return name + " " + symbol + " " + std::to_string(period) + " " + std::to_string(isRadioactive) + " " + groupNum.antiParse() + " " + antiParseBlock(block) + " " + std::to_string(atomicNumber) + " " + std::to_string(neutronNumber) + " " + std::to_string(atomicMass) + " " + antiParseEConfig();
}