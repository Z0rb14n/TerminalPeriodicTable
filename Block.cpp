//
//  Block.cpp
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-29.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#include "Block.h"
#include <string>

Block strBlock(std::string a){
  if (a == "S" || a == "s") return S;
  else if (a == "P" || a == "p") return P;
  else if (a == "D" || a == "d") return D;
  else if (a == "F" || a == "f") return F;
  else throw std::invalid_argument("Invalid block character: " + a);
}
std::string blockToString(Block A){
  if(A == S) return "S Block";
  else if (A == P) return "P Block";
  else if (A == D) return "D Block";
  else return "F Block";
}
std::string antiParseBlock(Block b){
  if(b == S) return "S";
  else if (b == P) return "P";
  else if (b == D) return "D";
  else if (b == F) return "F";
  else throw std::invalid_argument("Block may not be initialized.");
}