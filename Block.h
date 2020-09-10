//
//  Block.h
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-29.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#ifndef __PeriodicTable__Block__
#define __PeriodicTable__Block__

#include <string>

enum Block{
  S, P, D, F
};


Block strBlock(std::string a);
std::string blockToString(Block A);
std::string antiParseBlock(Block b);

#endif /* defined(__PeriodicTable__Block__) */
