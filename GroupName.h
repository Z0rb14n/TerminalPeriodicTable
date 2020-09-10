//
//  GroupName.h
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-29.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#ifndef __PeriodicTable__GroupName__
#define __PeriodicTable__GroupName__

#include <string>
#include "GroupNum.h"

enum GroupName {
  AlkaliMetal,
  AlkalineEarthMetal,
  Pnictogens,
  Chalcogens,
  Halogens,
  NobleGas,
  Transition,
  Lanthanide,
  Actinide,
  Other
};

std::string groupNameString(GroupName a);

GroupName groupToName(GroupNum a);

#endif /* defined(__PeriodicTable__GroupName__) */
