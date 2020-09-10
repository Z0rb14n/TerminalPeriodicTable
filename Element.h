//
//  Element.h
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-29.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#ifndef __PeriodicTable__Element__
#define __PeriodicTable__Element__

#include <string>
#include "GroupNum.h"
#include "GroupName.h"
#include "Block.h"
#include <vector>
#include "ElectronConfig.h"

class Element{
public:
		std::string name;
		std::string symbol;
		unsigned int period;
		bool isRadioactive;
		GroupNum groupNum;
		GroupName groupName;
		Block block;
		unsigned int atomicNumber;
		unsigned int neutronNumber;
		unsigned int approxAtomicMass;
		double atomicMass;
		std::vector<ElectronConfig> electron_Configuration;
		std::string getName(){ return name;}
		std::string getSymbol(){ return symbol;}
		unsigned int getPeriod(){ return period;}
		bool getRadioactive(){ return isRadioactive;}
		GroupNum getGroup(){ return groupNum;}
		GroupName getGroupName(){ return groupName;}
		Block getBlock(){ return block;}
		unsigned int getAtomicNumber(){ return atomicNumber;}
		unsigned int getNeutronNumber(){return neutronNumber;}
		unsigned int getApproxMass(){return approxAtomicMass;}
		double getAtomicMass(){return atomicMass;}
		std::vector<ElectronConfig> getEConfig(){return electron_Configuration;}
		Element(std::string a, std::string b, unsigned int c, bool d, GroupNum e,GroupName l, Block f, unsigned int g, unsigned int h, double i,
            std::vector<ElectronConfig> j);
		Element(std::string a, std::string b, unsigned int c, bool d, GroupNum e, Block f, unsigned int g,
            unsigned int h,
            double i,
            std::vector<ElectronConfig> j);
    Element(std::string fatString);
		void fixGroupName();
		std::string antiParseEConfig();
		void readElement();
  void edit(unsigned int valueToModify, std::string input);
  std::string serialize();
    std::string static booleanString(bool value);
  bool static stringToBoolean(std::string value);
  bool static compare(std::string str1, std::string str2);
};

#endif /* defined(__PeriodicTable__Element__) */
