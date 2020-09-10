//
//  GroupName.cpp
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-29.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#include "GroupNum.h"
#include "GroupName.h"

std::string groupNameString(GroupName a){
  if(a == AlkaliMetal) return "Alkali Metal";
  else if (a == AlkalineEarthMetal) return "Alkaline Earth Metal";
  else if (a == Pnictogens) return "Pnictogen";
  else if (a == Chalcogens) return "Chalcogen";
  else if (a == Halogens) return "Halogen";
  else if (a == NobleGas) return "Noble Gas";
  else if (a == Transition) return "Transition Metal";
  else if (a == Lanthanide) return "Lanthanide";
  else if (a == Actinide) return "Actinide";
  else return "Other";
}

GroupName groupToName(GroupNum a){
  if(a.number == 1) return AlkaliMetal;
  else if (a.number == 2) return AlkalineEarthMetal;
  else if (a.number == 15) return Pnictogens;
  else if (a.number == 16) return Chalcogens;
  else if (a.number == 17) return Halogens;
  else if (a.number == 18) return NobleGas;
  else if (a.str == "") return Transition;
  else return Other;
}
