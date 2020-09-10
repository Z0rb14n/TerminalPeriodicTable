//
//  ElementsOutput.h
//  PeriodicTable
//
//  Created by Jonathan Nah on 2020-08-30.
//  Copyright (c) 2020 Jonathan Nah. All rights reserved.
//

#ifndef __PeriodicTable__ElementsOutput__
#define __PeriodicTable__ElementsOutput__

#include <stdio.h>
#include <string>
#include "Element.h"
#include <vector>

class ElementsOutput {
public:
  static const std::string INPUT_FILE_NAME;
  static const std::string REVISION_DIR;
  static const std::string SAVED_REVISION_DIR;
  static const std::string LATEST_REVISION_NAME;
  static void deleteRevisions();
  static void makeRevision(std::vector<Element> elements);
  static void addRevision(std::string fileName, std::vector<Element> elements);
  static void saveRevision(std::vector<Element> elements);
  static bool hasRevision();
private:
  static void saveRevision(std::string fileName, std::vector<Element> elements);
};


#endif /* defined(__PeriodicTable__ElementsOutput__) */
